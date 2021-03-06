/*****************************************************************************

 @(#) xti_mosi.h,v 1.1.4.1 2004/01/12 23:44:51 brian Exp

 -----------------------------------------------------------------------------

     Copyright (C) 2001-2004 OpenSS7 Corporation.  All Rights Reserved.

                                  PUBLIC LICENSE

     This license is provided without fee, provided that the above copy-
     right notice and this public license must be retained on all copies,
     extracts, compilations and derivative works.  Use or distribution of
     this work in a manner that restricts its use except as provided here
     will render this license void.

     The author(s) hereby waive any and all other restrictions in respect
     of their copyright in this software and its associated documentation.
     The authors(s) of this software place in the public domain any novel
     methods or processes which are embodied in this software.

     The author(s) undertook to write it for the sake of the advancement
     of the Arts and Sciences, but it is provided as is, and the author(s)
     will not take any responsibility in it.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any success regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Last Modified 2004/01/12 23:44:51 by brian

 *****************************************************************************/

#ifndef _XTI_MOSI_H
#define _XTI_MOSI_H

#ident "@(#) xti_mosi.h,v LiS-2_16_18-9 (1.1.4.1) Copyright (c) 1997-2004 OpenSS7 Corporation"

#ifdef __BEGIN_DECLS
/* *INDENT-OFF* */
__BEGIN_DECLS
/* *INDENT-ON* */
#endif

/*
   mosi address structure 
 */

struct t_mosiaddr {
	t_uscalar_t flags;
	t_scalar_t osi_ap_inv_id;
	t_scalar_t osi_ae_inv_id;
	unsigned int osi_apt_len;
	unsigned int osi_aeq_len;
	unsigned int osi_paddr_len;
	unsigned char osi_addr[MAX_ADDR];
};

#define T_ISO_APCO	0x0200
#define T_ISO_APCL	0x0300
#define T_AP_CNTX_NAME	0x1
#define T_AP_PCL	0x2

#define T_OPT_VALEN(opt) (opt->len - sizeof(struct t_opthder)).

/*
   presentation context definition and result list option 
 */

struct t_ap_pco_el {
	t_scalar_t count;
	t_scalar_t offset;
};

/*
   presentation context item header 
 */

struct t_ap_pc_item {
	t_scalar_t pci;			/* unique odd integer */
	t_scalar_t res;			/* result of negotiation */
};

/*
   presentation context item element 
 */

struct t_app_syn_off {
	t_scalar_t size;		/* length of syntax object identifier contents */
	t_scalar_t offset;		/* offset of object identifier for the syntax */
};

/*
   values for res of a presentation context item 
 */

#define T_PCL_ACCEPT		    0x0000	/* pres. context accepted */
#define T_PCL_USER_REJ		    0x0100	/* pres. context rejected by perr application */
#define T_PCL_PREJ_RSN_NSPEC	    0x0200	/* prov. reject: no reason specified */
#define T_PCL_PREJ_A_SYTX_NSUP	    0x0201	/* prov. reject: abstract syntax not supported */
#define T_PCL_PREJ_T_SYTX_NSUP	    0x0202	/* prov. reject: transfer syntax not supported */
#define T_PCL_PREJ_LMT_DCS_EXCEED   0x0203	/* prov. reject: local limit on DCS exceeded */

/*
   reason codes for disconnection 
 */

#define T_AC_U_AARE_NONE	    0x0001	/* con rej by peer user: no reason given */
#define T_AC_C_U_AARE_ACN	    0x0002	/* con rej: application context name not supported */
#define T_AC_U_AARE_APT		    0x0003	/* con rej: AP title not recognized */
#define T_AC_U_AARE_AEQ		    0x0005	/* con rej: AE qualifier not recognized */
#define T_AC_U_AARE_PEER_AUTH	    0x000e	/* con rej: authentication required */
#define T_AC_P_ABRT_NSPEC	    0x0011	/* aborted by peer: not reason given */
#define T_AC_P_AARE_VERSION	    0x0012	/* con rej: no common version */

#ifdef __END_DECLS
/* *INDENT-OFF* */
__END_DECLS
/* *INDENT-ON* */
#endif

#endif				/* _XTI_MOSI_H */
