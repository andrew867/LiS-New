/*
 *  ldlconfig: A configuration helper for ldl clients
 *
 *  Copyright (C) 1998 Ole Husgaard (sparre@login.dknet.dk)
 *  Copyright (C) 1999 David Grothe (dave@gcom.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ident "@(#) LiS ldlconfig.c 1.4 12/11/00"

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <sys/stream.h>		/* mainly for linux-mdep.h */
#include <sys/ioctl.h>
#include <sys/dlpi.h>
#include <sys/stropts.h>
#include <sys/ldl.h>

#define MAX_DL_ADDR_LEN 128
#define MAX_DL_SAP_LEN 64

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;

unsigned char my_addr[MAX_DL_ADDR_LEN];
unsigned char my_brd_addr[MAX_DL_ADDR_LEN];
unsigned char my_dlsap[MAX_DL_ADDR_LEN + MAX_DL_SAP_LEN];
unsigned char my_sap[MAX_DL_SAP_LEN];

int addr_len;	/* Data Link address length	*/
int sap_len;	/* Data Link SAP length		*/
int sap_first;	/* Flag: SAP first in DLSAP	*/
int hw_type;	/* ARP hardware type		*/
int	verbose = 0 ;

int		 filed = -1 ;
char		*if_name = "eth0" ;
unsigned long	 bind_sap = 0xAA ;
int		 bind_specified ;
unsigned long	 flag_opts[32] ;
int		 nxt_flag_opt ;
unsigned long	 promisc_opts[32] ;
int		 nxt_promisc_opt ;
unsigned long	 framing = 0 ;
int		 print_info = 0 ;




char *hex(unsigned char c)
{
	static char s[3];
	static char h[16] = "0123456789abcdef";

	s[0] = h[c >> 4];
	s[1] = h[c & 15];
	s[2] = '\0';

	return s;
}

void dumpbuf(struct strbuf buf)
{
	int i, j;
	int lines = (buf.len == 0) ? 0 : ((buf.len-1) >> 4) + 1;
	char s1[128], s2[128];

	printf("  Len = %d  MaxLen = %d\n", buf.len, buf.maxlen);
	for (i = 0; i < lines; ++i) {
		strcpy(s1, "  ");
		strcpy(s2, "  ");
		for (j = 0; j < 16; ++j) {
			if (16*i+j < buf.len) {
				unsigned char c = buf.buf[16*i+j];

				strcat(s1, hex(c));
				strcat(s1, " ");
				if (isprint(c)) {
					char s3[2];

					s3[0] = c;
					s3[1] = '\0';
					strcat(s2, s3);
				} else
					strcat(s2, ".");
				
			} else {
				strcat(s1, "   ");
				strcat(s2, " ");
			}
			if (j == 7) {
				strcat(s1, " ");
				strcat(s2, " ");
			}
		}
		printf("  %s  %s\n", s1, s2);
	}
}

void dumphex(unsigned char *data, int len)
{
	while (len--) {
		printf("%s%s", hex(*data), (len) ? ":" : "");
		++data;
	}
}

void dumpbytes(char *prompt, unsigned char *data, int len)
{
	printf("%s: ", prompt);
	dumphex(data, len) ;
	printf("\n");
}

void dumpaddr(char *prompt, unsigned char *addr, int addrlen)
{
	printf("%s: ", prompt);
	if (addrlen) {
		printf("%02x", (int)*addr++);
		--addrlen;
	} else {
		printf("(none)\n");
		return;
	}
	while(addrlen--)
		printf(":%02x", (int)*addr++);
	printf("\n");
}

void dump8022(char *prompt, unsigned char *buf, int length)
{
    int		i ;
    int		ff_cnt = 0;

    for (i = 0; i < 6; i++)
    {
	if (buf[i] == 0xff) ff_cnt++ ;
    }

    printf("%s: ", prompt) ;
    printf("daddr=") ;
    dumphex(buf, 6) ;
    printf(" saddr=") ;
    dumphex(buf+6, 6) ;
    printf("\n    length=") ;
    dumphex(buf+12, 2) ;
    printf(" dsap=%02x ssap=%02x ctl=%02x\n", buf[14], buf[15], buf[16]) ;
    if (length >= 17 && ff_cnt != 6)
    {
	dumpbytes("    data", buf+17, length-17) ;
    }
}

#ifdef TR
void dumptr(char *prompt, unsigned char *buf, int length)
{				/* dump token ring header/buffer */
    tr_hdr_t		*hdrp ;
    rcf_t		*rcfp ;
    tr_llc_frm_hdr_t	*llcp ;
    int			 rtelgth = 0 ;
    int			 hdrsize ;

    hdrp = (tr_hdr_t *) buf ;
    rcfp = (rcf_t *) (hdrp+1) ;

    printf("%s: ", prompt) ;
    printf("acf=%02x fcf=%02x ", hdrp->acf, hdrp->fcf) ;
    printf("daddr=") ;
    dumphex(hdrp->dst_addr, sizeof(hdrp->dst_addr)) ;
    printf(" saddr=") ;
    dumphex(hdrp->src_addr, sizeof(hdrp->src_addr)) ;

    if (hdrp->src_addr[0] & SADDR_0_RTE_PRES)
    {
	rtelgth = rcfp->bl & RCF_0_LLLLL ;
	printf(" bl=%02x df=%02x", rcfp->bl, rcfp->df) ;
	llcp = (tr_llc_frm_hdr_t *) (buf + sizeof(*hdrp) + rtelgth) ;
    }
    else
	llcp = (tr_llc_frm_hdr_t *) (buf + sizeof(*hdrp)) ;

    printf(" dsap=%02x ssap=%02x ctl=%02x\n",
		llcp->llc_dsap, llcp->llc_ssap, llcp->llc_ctl) ;

    hdrsize = sizeof(*hdrp) + sizeof(*llcp) + rtelgth ;
    if (length >= hdrsize)
    {
	dumpbytes("    data", buf+hdrsize, length-hdrsize) ;
    }
}
#endif

unsigned long do_findppa(int fd, char *interface)
{
	union {
		char interface[256];
		unsigned long ppa;
	} data;
	struct strioctl strioctl;

	strioctl.ic_cmd = LDL_FINDPPA;
	strioctl.ic_timout = 3;
	strioctl.ic_len = sizeof(data);
	strioctl.ic_dp = (char *)&data;
	strcpy(data.interface, interface);
	
	if (ioctl(fd, I_STR, &strioctl) < 0) {
		perror("do_findppa: ioctl()");
		return (unsigned long)-1;
	}

	return data.ppa;
}

int do_set_flags(int fd, int flags)
{
	struct ldl_flags_ioctl	ioc ;
	struct strioctl strioctl;

	ioc.flags = flags ;
	ioc.mask  = 0xff ;

	strioctl.ic_cmd = LDL_SETFLAGS;
	strioctl.ic_timout = 3;
	strioctl.ic_len = sizeof(ioc);
	strioctl.ic_dp = (char *)&ioc;
	
	if (ioctl(fd, I_STR, &strioctl) < 0) {
		perror("do_set_flags: ioctl()");
		return -1;
	}

	return 0 ;
}

int do_info(int fd)
{
	dl_info_req_t request;
	struct {
		dl_info_ack_t ack;
		unsigned char extra[1024];
	} reply;
	int flags;
	struct strbuf ctlbuf;
	dl_error_ack_t *err_ack;

	if (verbose > 2)
		printf("do_info: Sending DL_INFO_REQ\n");

	request.dl_primitive = DL_INFO_REQ;
	ctlbuf.maxlen = ctlbuf.len = sizeof(request);
	ctlbuf.buf = (char *)&request;
	if (putmsg(fd, &ctlbuf, NULL, 0) < 0) {
		perror("do_info: putmsg()");
		return -1;
	}

	ctlbuf.maxlen = sizeof(reply);
	ctlbuf.len = 0;
	ctlbuf.buf = (char *)&reply;
	flags = RS_HIPRI;
	flags = 0;
	if (getmsg(fd, &ctlbuf, NULL, &flags) < 0) {
		perror("do_info: getmsg()");
		return -1;
	}

	if (verbose  > 2) {
		printf("do_info: Buffer dump:\n");
		dumpbuf(ctlbuf);
	}
		
	if (ctlbuf.len < sizeof(dl_ulong)) {
		fprintf(stderr, "do_info: Bad reply length %d\n", ctlbuf.len);
		return -1;
	}

	switch (reply.ack.dl_primitive) {
	case DL_ERROR_ACK:
		printf("do_info: Got DL_ERROR_ACK\n");
		if (ctlbuf.len < sizeof(dl_error_ack_t)) {
			fprintf(stderr, "do_info: Bad DL_ERROR_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		err_ack = (dl_error_ack_t *)&reply;
		printf("do_info: error ack:\n");
		printf("\tprimitive=%lu, errno=%lu, unix_errno=%lu\n", err_ack->dl_error_primitive, err_ack->dl_errno, err_ack->dl_unix_errno);
		return -1;
			
	case DL_INFO_ACK:
		if (verbose > 2)
			printf("do_info: Got DL_INFO_ACK\n");
		if (ctlbuf.len < sizeof(dl_info_ack_t)) {
			fprintf(stderr, "do_info: Bad DL_INFO_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		if (verbose > 1) {
			printf("do_info: info ack:\n");
			printf("\tprimitive=%lu\n", reply.ack.dl_primitive);
			printf("\tmin_sdu=%lu\n", reply.ack.dl_min_sdu);
			printf("\tmax_sdu=%lu\n", reply.ack.dl_max_sdu);
			printf("\taddr_length=%lu\n", reply.ack.dl_addr_length);
			printf("\tmac_type=%lu\n", reply.ack.dl_mac_type);
			printf("\treserved=%lu\n", reply.ack.dl_reserved);
			printf("\tcurrent_state=%lu\n", reply.ack.dl_current_state);
			printf("\tsap_length=%ld\n", reply.ack.dl_sap_length);
			printf("\tservice_mode=%lu\n", reply.ack.dl_service_mode);
			printf("\tqos_length=%lu\n", reply.ack.dl_qos_length);
			printf("\tqos_offset=%lu\n", reply.ack.dl_qos_offset);
			printf("\tqos_range_length=%lu\n", reply.ack.dl_qos_range_length);
			printf("\tqos_range_offset=%lu\n", reply.ack.dl_qos_range_offset);
			printf("\tprovider_style=%ld\n", reply.ack.dl_provider_style);
			printf("\taddr_offset=%lu\n", reply.ack.dl_addr_offset);
			printf("\tversion=%lu\n", reply.ack.dl_version);
			printf("\tbrdcst_addr_length=%lu\n", reply.ack.dl_brdcst_addr_length);
			printf("\tbrdcst_addr_offset=%lu\n", reply.ack.dl_brdcst_addr_offset);
			printf("\tgrowth=%lu\n", reply.ack.dl_growth);
			if (reply.ack.dl_addr_length && reply.ack.dl_addr_offset &&
			    reply.ack.dl_addr_offset + reply.ack.dl_addr_length <= ctlbuf.len)
				dumpaddr("\tAddress", (unsigned char *)
					&ctlbuf.buf[reply.ack.dl_addr_offset], 
					reply.ack.dl_addr_length);
			if (reply.ack.dl_brdcst_addr_length && reply.ack.dl_brdcst_addr_offset &&
			    reply.ack.dl_brdcst_addr_offset + reply.ack.dl_brdcst_addr_length <= ctlbuf.len)
				dumpaddr("\tBroadcast address", 
				   (unsigned char *)
				   &ctlbuf.buf[reply.ack.dl_brdcst_addr_offset],
				   reply.ack.dl_brdcst_addr_length);
			if (reply.ack.dl_qos_length >= sizeof(unsigned long) && reply.ack.dl_qos_offset) {
				dl_qos_cl_sel1_t *sel = (dl_qos_cl_sel1_t *)((char *)&reply.ack + reply.ack.dl_qos_offset);

				printf("\tQOS selection:\n");
				if (sel->dl_qos_type != DL_QOS_CL_SEL1)
					printf("\t\tUnknown type %lu, expected %lu\n", sel->dl_qos_type, (dl_ulong)DL_QOS_CL_SEL1);
				else {
					printf("\t\ttrans_delay=%ld\n", sel->dl_trans_delay);
					printf("\t\tpriority=%ld\n", sel->dl_priority);
					printf("\t\tprotection=%ld\n", sel->dl_protection);
					printf("\t\tresidual_error=%ld\n", sel->dl_residual_error);
				}
			}
			if (reply.ack.dl_qos_range_length >= sizeof(unsigned long) && reply.ack.dl_qos_range_offset) {
				dl_qos_cl_range1_t *range = (dl_qos_cl_range1_t *)((char *)&reply.ack + reply.ack.dl_qos_range_offset);

				printf("\tQOS range:\n");
				if (range->dl_qos_type != DL_QOS_CL_RANGE1)
					printf("\t\tUnknown type %lu, expected %lu\n", range->dl_qos_type, (dl_ulong)DL_QOS_CL_RANGE1);
				else {
					printf("\t\ttrans_delay(target, accept)=(%ld, %ld)\n",
					       range->dl_trans_delay.dl_target_value,
					       range->dl_trans_delay.dl_accept_value);
					printf("\t\tpriority(min, max)=(%ld, %ld)\n",
					       range->dl_priority.dl_min, range->dl_priority.dl_max);
					printf("\t\tprotection(min, max)=(%ld, %ld)\n",
					       range->dl_protection.dl_min, range->dl_protection.dl_max);
					printf("\t\tresidual_error=%ld\n", range->dl_residual_error);
				}
			}
		}
		if (reply.ack.dl_sap_length < 0) {
			sap_len = -reply.ack.dl_sap_length;
			sap_first = 0;
		} else {
			sap_len = reply.ack.dl_sap_length;
			sap_first = 1;
		}
		addr_len = reply.ack.dl_addr_length - sap_len;
		if (reply.ack.dl_addr_length != 0 && 
		    reply.ack.dl_addr_offset != 0) {
			memcpy(my_dlsap, &ctlbuf.buf[reply.ack.dl_addr_offset], addr_len + sap_len);
			if (sap_first) {
				memcpy(my_sap, &ctlbuf.buf[reply.ack.dl_addr_offset], sap_len);
				memcpy(my_addr, &ctlbuf.buf[reply.ack.dl_addr_offset + sap_len], addr_len);
			} else {
				memcpy(my_addr, &ctlbuf.buf[reply.ack.dl_addr_offset], addr_len);
				memcpy(my_sap, &ctlbuf.buf[reply.ack.dl_addr_offset + addr_len], sap_len);
			}
		}
		if (reply.ack.dl_brdcst_addr_length != 0 && 
		    reply.ack.dl_brdcst_addr_offset != 0) {
			assert(reply.ack.dl_addr_length == 0 ||
			       reply.ack.dl_brdcst_addr_length == addr_len);
			memcpy(my_brd_addr, &ctlbuf.buf[reply.ack.dl_brdcst_addr_offset], reply.ack.dl_brdcst_addr_length);
		}
		break;

	default:
		fprintf(stderr, "do_info: Unknown reply primitive=%lu\n", reply.ack.dl_primitive);
		return -1;
	}
	return 0;
}

int do_attach(int fd, dl_ulong ppa)
{
	dl_attach_req_t request;
	struct {
		dl_ok_ack_t ack;
		unsigned char extra[1024];
	} reply;
	int flags;
	struct strbuf ctlbuf;
	dl_error_ack_t *err_ack;

	if (verbose > 2)
		printf("do_attach: Sending DL_ATTACH_REQ\n");

	request.dl_primitive = DL_ATTACH_REQ;
	request.dl_ppa = ppa;
	ctlbuf.maxlen = ctlbuf.len = sizeof(request);
	ctlbuf.buf = (char *)&request;
	if (putmsg(fd, &ctlbuf, NULL, 0) < 0) {
		perror("do_attach: putmsg()");
		return -1;
	}

	ctlbuf.maxlen = sizeof(reply);
	ctlbuf.len = 0;
	ctlbuf.buf = (char *)&reply;
	flags = RS_HIPRI;
	if (getmsg(fd, &ctlbuf, NULL, &flags) < 0) {
		perror("do_attach: getmsg()");
		return -1;
	}

	if (verbose > 2) {
		printf("do_attach: Buffer dump:\n");
		dumpbuf(ctlbuf);
	}
		
	if (ctlbuf.len < sizeof(dl_ulong)) {
		fprintf(stderr, "do_attach: Bad reply length %d\n", ctlbuf.len);
		return -1;
	}

	switch (reply.ack.dl_primitive) {
	case DL_ERROR_ACK:
		printf("do_attach: Got DL_ERROR_ACK\n");
		if (ctlbuf.len < sizeof(dl_error_ack_t)) {
			fprintf(stderr, "do_attach: Bad DL_ERROR_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		err_ack = (dl_error_ack_t *)&reply;
		printf("do_attach: error ack:\n");
		printf("\tprimitive=%lu, errno=%lu, unix_errno=%lu\n", err_ack->dl_error_primitive,
		       err_ack->dl_errno, err_ack->dl_unix_errno);
		return -1;
			
	case DL_OK_ACK:
		if (verbose > 2)
			printf("do_attach: Got DL_OK_ACK\n");
		if (ctlbuf.len < sizeof(dl_ok_ack_t)) {
			fprintf(stderr, "do_attach: Bad DL_OK_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		if (verbose > 1) {
			printf("do_attach: ok ack:\n");
			printf("\tprimitive=%lu\n", reply.ack.dl_primitive);
			printf("\tcorrect_primitive=%lu\n", reply.ack.dl_correct_primitive);
		}
		break;

	default:
	fprintf(stderr, "do_attach: Unknown reply primitive=%lu\n", reply.ack.dl_primitive);
		return -1;
	}
	return 0;
}


int do_promiscon(int fd, unsigned long level)
{
	dl_promiscon_req_t request;
	struct {
		dl_ok_ack_t ack;
		unsigned char extra[1024];
	} reply;
	int flags;
	struct strbuf ctlbuf;
	dl_error_ack_t *err_ack;

	if (verbose > 2)
		printf("do_promiscon: Sending DL_PROMISCON_REQ\n");

	request.dl_primitive = DL_PROMISCON_REQ;
	request.dl_level = level;
	ctlbuf.maxlen = ctlbuf.len = sizeof(request);
	ctlbuf.buf = (char *)&request;
	if (putmsg(fd, &ctlbuf, NULL, 0) < 0) {
		perror("do_promiscon: putmsg()");
		return -1;
	}

	ctlbuf.maxlen = sizeof(reply);
	ctlbuf.len = 0;
	ctlbuf.buf = (char *)&reply;
	flags = RS_HIPRI;
	if (getmsg(fd, &ctlbuf, NULL, &flags) < 0) {
		perror("do_promiscon: getmsg()");
		return -1;
	}

	if (verbose > 2) {
		printf("do_promiscon: Buffer dump:\n");
		dumpbuf(ctlbuf);
	}
		
	if (ctlbuf.len < sizeof(dl_ulong)) {
		fprintf(stderr, "do_promiscon: Bad reply length %d\n", ctlbuf.len);
		return -1;
	}

	switch (reply.ack.dl_primitive) {
	case DL_ERROR_ACK:
	    printf("do_promiscon: Got DL_ERROR_ACK\n");
	    if (ctlbuf.len < sizeof(dl_error_ack_t)) {
		fprintf(stderr, "do_promiscon: Bad DL_ERROR_ACK length %d\n",
			ctlbuf.len);
		return -1;
	    }
	    err_ack = (dl_error_ack_t *)&reply;
	    printf("do_promiscon: error ack:\n");
	    printf("\tprimitive=%lu, errno=%lu, unix_errno=%lu\n",
		   err_ack->dl_error_primitive,
		   err_ack->dl_errno, err_ack->dl_unix_errno);
	    return -1;
			
	case DL_OK_ACK:
	    if (verbose > 2)
		printf("do_promiscon: Got DL_OK_ACK\n");
	    if (ctlbuf.len < sizeof(dl_ok_ack_t)) {
		fprintf(stderr, "do_promiscon: Bad DL_OK_ACK length %d\n",
			ctlbuf.len);
		return -1;
	    }
	    if (verbose > 1) {
		printf("do_promiscon: ok ack:\n");
		printf("\tprimitive=%lu\n", reply.ack.dl_primitive);
		printf("\tcorrect_primitive=%lu\n",
		       reply.ack.dl_correct_primitive);
	    }
	    if (reply.ack.dl_correct_primitive != request.dl_primitive)
	    {
		fprintf(stderr, "do_promiscon: "
				"DL_OK_ACK acks wrong primitive\n") ;
		return -1 ;
	    }
	    break;

	default:
	    fprintf(stderr, "do_promiscon: Unknown reply primitive=%lu\n",
		    reply.ack.dl_primitive);
	    return -1;
	}
	return 0;
}

int do_bind(int fd, dl_ulong sap)
{
	dl_bind_req_t request;
	struct {
		dl_bind_ack_t ack;
		unsigned char extra[1024];
	} reply;
	int flags;
	struct strbuf ctlbuf;
	dl_error_ack_t *err_ack;

	if (verbose > 2)
		printf("do_bind(sap=0x%lx): Sending DL_BIND_REQ\n", sap);

	request.dl_primitive = DL_BIND_REQ;
	request.dl_sap = sap;
	request.dl_max_conind = 0;
	request.dl_service_mode = DL_CLDLS;
	request.dl_conn_mgmt = 0;
	request.dl_xidtest_flg = 0;
	ctlbuf.maxlen = ctlbuf.len = sizeof(request);
	ctlbuf.buf = (char *)&request;
	if (putmsg(fd, &ctlbuf, NULL, 0) < 0) {
		perror("do_bind: putmsg()");
		return -1;
	}

	ctlbuf.maxlen = sizeof(reply);
	ctlbuf.len = 0;
	ctlbuf.buf = (char *)&reply;
	flags = RS_HIPRI;
	if (getmsg(fd, &ctlbuf, NULL, &flags) < 0) {
		perror("do_bind: getmsg()");
		return -1;
	}

	if (verbose > 2) {
		printf("do_bind: Buffer dump:\n");
		dumpbuf(ctlbuf);
	}
		
	if (ctlbuf.len < sizeof(dl_ulong)) {
		fprintf(stderr, "do_bind: Bad reply length %d\n", ctlbuf.len);
		return -1;
	}

	switch (reply.ack.dl_primitive) {
	case DL_ERROR_ACK:
		printf("do_bind: Got DL_ERROR_ACK\n");
		if (ctlbuf.len < sizeof(dl_error_ack_t)) {
			fprintf(stderr, "do_bind: Bad DL_ERROR_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		err_ack = (dl_error_ack_t *)&reply;
		printf("do_bind: error ack:\n");
		printf("\tprimitive=%lu, errno=%lu, unix_errno=%lu\n", err_ack->dl_error_primitive,
		       err_ack->dl_errno, err_ack->dl_unix_errno);
		return -1;
			
	case DL_BIND_ACK:
		if (verbose > 2)
			printf("do_bind: Got DL_BIND_ACK\n");
		if (ctlbuf.len < sizeof(dl_bind_ack_t)) {
			fprintf(stderr, "do_bind: Bad DL_BIND_ACK length %d\n", ctlbuf.len);
			return -1;
		}
		if (verbose > 1) {
			printf("do_bind: bind ack:\n");
			printf("\tprimitive=%lu\n", reply.ack.dl_primitive);
			printf("\tsap=%lu\n", reply.ack.dl_sap);
			printf("\taddr_length=%lu\n", reply.ack.dl_addr_length);
			printf("\taddr_offset=%lu\n", reply.ack.dl_addr_offset);
			printf("\tmax_conind=%lu\n", reply.ack.dl_max_conind);
			printf("\txidtest_flg=%lu\n", reply.ack.dl_xidtest_flg);
			dumpbytes("\tSAP",
				  (unsigned char *)&reply.ack + 
					reply.ack.dl_addr_offset,
				  reply.ack.dl_addr_length);
		}
		break;

	default:
		fprintf(stderr, "do_bind: Unknown reply primitive=%lu\n", reply.ack.dl_primitive);
		return -1;
	}
	return 0;
}



void	print_usage(void)
{
    printf("ldlconfig usage:\n") ;
    printf("  -a<name>    Name of interface to attach\n") ;
    printf("  -b<sap>     SAP to bind\n") ;
    printf("  -d<filed>   Use file descriptor number\n");
    printf("  -f<flag>    Flag to set w/ioctl\n") ;
    printf("  -F<framing> Framing option\n") ;
    printf("  -h          Print this help text\n") ;
    printf("  -I          Print info ack\n") ;
    printf("  -p<mode>    Set promiscuous mode\n") ;
    printf("  -v<mask>    Set verbose mask\n") ;

    printf("<flag> = PEDANTIC_STANDARD or RAW\n") ;
    printf("<mode> = PHYS or SAP or MULTI\n") ;
    printf("<framing> = EII or 802.2 or SNAP or 802.3 or RAWLLC\n") ;

} /* print_usage */

void get_options(int argc, char **argv)
{
    char   *p;						/* option ptr */

    for (argc--, argv++; argc > 0; argc--, argv++)	/* THRU the options */
    {
	p = *argv;					/* set option ptr */

	if (*p++ != '-')				/* skip over '-' */
	{						/* busted option */
	    printf ("Options must begin with a '-'\n");
	    print_usage();
	    exit (1);					/* invalid option */
	}

	switch (*p++)					/* point at option arg*/
	{
	case 'a':
	    if_name = p ;
	    break;
	case 'b':
	    bind_sap = strtol(p, NULL, 0);
	    bind_specified = 1 ;
	    break;
	case 'd':
	    filed = strtol(p, NULL, 0);
	    break ;
	case 'f':
	    if (nxt_flag_opt >= 32)
	    {
		printf("Too many -f options\n") ;
		exit(1) ;
	    }

	    if (strcmp(p, "PEDANTIC_STANDARD") == 0)
		flag_opts[nxt_flag_opt++] = LDLFLAG_PEDANTIC_STANDARD;
	    else
	    if (strcmp(p, "RAW") == 0)
		flag_opts[nxt_flag_opt++] = LDLFLAG_RAW;
	    else
	    {
		printf ("Improper flag mnemonic: %s\n", p);
		print_usage ();
		exit (1);				/* invalid option */
	    }
	    break ;
	case 'F':
	    if (strcmp(p, "EII") == 0)
		framing = LDL_FRAME_EII ;
	    else
	    if (strcmp(p, "802.2") == 0)
		framing = LDL_FRAME_802_2 ;
	    else
	    if (strcmp(p, "802.3") == 0)
		framing = LDL_FRAME_802_3 ;
	    else
	    if (strcmp(p, "SNAP") == 0)
		framing = LDL_FRAME_SNAP ;
	    else
	    if (strcmp(p, "RAWLLC") == 0)
		framing = LDL_FRAME_RAW_LLC ;
	    else
	    {
		printf("Improper framing mnemonic: %s\n", p) ;
		print_usage ();
		exit (1);				/* invalid option */
	    }

	    break ;
	case 'h':
	    print_usage() ;
	    exit(0) ;
	case 'I':
	    print_info = 1 ;
	    break ;
	case 'p':
	    if (nxt_promisc_opt >= 32)
	    {
		printf("Too many -p options\n") ;
		exit(1) ;
	    }

	    if (strcmp(p, "PHYS") == 0)
		promisc_opts[nxt_promisc_opt++] = DL_PROMISC_PHYS;
	    else
	    if (strcmp(p, "SAP") == 0)
		promisc_opts[nxt_promisc_opt++] = DL_PROMISC_SAP;
	    else
	    if (strcmp(p, "PROMISC_MULTI") == 0)
		promisc_opts[nxt_promisc_opt++] = DL_PROMISC_MULTI;
	    else
	    {
		printf ("Improper promiscuous mnemonic: %s\n", p);
		print_usage ();
		exit (1);				/* invalid option */
	    }
	    break ;
	case 'v':
	    verbose = strtol(p, NULL, 0);
	    break;

	default:				/* user needs help */
	    p -= 2;				/* backup to the '-' */
	    printf ("Option %s not recognized\n", p);
	    print_usage ();
	    exit (1);				/* invalid option */
	}
    }

}

int main(int argc, char **argv)
{
    int			fd ;
    int			i ;
    unsigned long	ppa ;

    get_options(argc, argv) ;

    if (filed >= 0)
	fd = filed ;
    else
    {
	fd = open("/dev/ldl", O_RDWR) ;
	if (fd < 0)
	{
	    perror("/dev/ldl") ;
	    exit(1) ;
	}
    }

    ppa = do_findppa(fd, if_name);
    if (ppa == (unsigned long)-1)
    {
	fprintf(stderr, "Unable to find PPA for interface \"%s\".\n",
		if_name);
	exit(1);
    }

    if (do_attach(fd, ppa | framing) < 0)
	    exit(1);

    for (i = 0; i < nxt_flag_opt; i++)
    {
	if (do_set_flags(fd, flag_opts[i]) < 0)
	    exit(1) ;
    }

    for (i = 0; i < nxt_promisc_opt; i++)
    {
	if (do_promiscon(fd, promisc_opts[i]) < 0)
	    exit(1);
    }

    if (bind_specified && do_bind(fd, bind_sap) < 0)
	exit(1);

    if (print_info)
    {
	if (verbose > 2)
	    printf("INFO after ATTACH and BIND:\n");
	if (do_info(fd) < 0)
	    exit(1);
    }

    exit(0) ;			/* everything is OK */
    return(0) ;
}
