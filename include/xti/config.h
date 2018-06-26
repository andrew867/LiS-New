/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/*****************************************************************************
 BEGINNING OF SEPARATE COPYRIGHT MATERIAL vim: ft=c
 *****************************************************************************

 @(#) config.h,v LiS-2_16_18-9(1.1.4.1) 2004/01/12 23:44:49

 -----------------------------------------------------------------------------

 Copyright (c) 2001-2004  OpenSS7 Corporation <http://www.openss7.com>
 Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 details.

 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 Ave, Cambridge, MA 02139, USA.

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

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 -----------------------------------------------------------------------------

 Last Modified 2004/01/12 23:44:49 by brian

 *****************************************************************************/

/*
 *  These are my header declarations before autoconf.
 */

/*****************************************************************************

 Copyright (c) 2001-2004  OpenSS7 Corporation <http://www.openss7.com>
 Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>

 *****************************************************************************
 ENDING OF SEPARATE COPYRIGHT MATERIAL vim: ft=c
 *****************************************************************************/

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define if your C compiler doesn't accept -c and -o together.  */
/* #undef NO_MINUS_C_MINUS_O */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you have the bcopy function.  */
/* #undef HAVE_BCOPY */

/* Define if you have the bzero function.  */
/* #undef HAVE_BZERO */

/* Define if you have the index function.  */
/* #undef HAVE_INDEX */

/* Define if you have the memcpy function.  */
#define HAVE_MEMCPY 1

/* Define if you have the memset function.  */
#define HAVE_MEMSET 1

/* Define if you have the pthread_getspecific function.  */
/* #undef HAVE_PTHREAD_GETSPECIFIC */

/* Define if you have the pthread_key_create function.  */
/* #undef HAVE_PTHREAD_KEY_CREATE */

/* Define if you have the pthread_mutex_destroy function.  */
#define HAVE_PTHREAD_MUTEX_DESTROY 1

/* Define if you have the pthread_mutex_init function.  */
#define HAVE_PTHREAD_MUTEX_INIT 1

/* Define if you have the pthread_mutex_lock function.  */
#define HAVE_PTHREAD_MUTEX_LOCK 1

/* Define if you have the pthread_mutex_unlock function.  */
#define HAVE_PTHREAD_MUTEX_UNLOCK 1

/* Define if you have the pthread_once function.  */
/* #undef HAVE_PTHREAD_ONCE */

/* Define if you have the pthread_setspecific function.  */
/* #undef HAVE_PTHREAD_SETSPECIFIC */

/* Define if you have the rindex function.  */
/* #undef HAVE_RINDEX */

/* Define if you have the strchr function.  */
#define HAVE_STRCHR 1

/* Define if you have the strcmp function.  */
#define HAVE_STRCMP 1

/* Define if you have the strrchr function.  */
#define HAVE_STRRCHR 1

/* Define if you have the <dlfcn.h> header file.  */
#define HAVE_DLFCN_H 1

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <linux/tihdr.h> header file.  */
/* #undef HAVE_LINUX_TIHDR_H */

/* Define if you have the <linux/timod.h> header file.  */
/* #undef HAVE_LINUX_TIMOD_H */

/* Define if you have the <pthread.h> header file.  */
#define HAVE_PTHREAD_H 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <stropts.h> header file.  */
/* #undef HAVE_STROPTS_H */

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/poll.h> header file.  */
#define HAVE_SYS_POLL_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/stropts.h> header file.  */
#define HAVE_SYS_STROPTS_H 1

/* Define if you have the <sys/tihdr.h> header file.  */
#define HAVE_SYS_TIHDR_H 1

/* Define if you have the <sys/timod.h> header file.  */
#define HAVE_SYS_TIMOD_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <tihdr.h> header file.  */
/* #undef HAVE_TIHDR_H */

/* Define if you have the <timod.h> header file.  */
/* #undef HAVE_TIMOD_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define to get GNU extensions. */
#define _GNU_SOURCE 1

/* Define to get XOPEN extensions. */
#define _XOPEN_SOURCE 1

/* Define to get reentrant versions of functions. */
#define _REENTRANT 1

/* Define for the linux operating system. */
#define __LINUX__ 1

/* Define to use Linux STREAMS under linux. */
#define __LINUX_WITH_LIS__ 1

/* Define to use Linux Fast-STREAMS under linux. */
/* #undef __LINUX_WITH_LFS__ */

/* Define to use Linux STREAMS ABI under linux. */
/* #undef __LINUX_WITH_ABI__ */

/* Define for System V Release 3.x operating system. */
/* #undef __SVR3__ */

/* Define for System V Release 4.x operating system. */
/* #undef __SVR4__ */

/* Define for OSF/1 1.2 derived operating system. */
/* #undef __OSF__ */

/* Define if thread safety required. */
#define XNET_THREAD_SAFE 1

/* Define if stropts.h defines t_scalar_t. */
/* #undef t_scalar_t */

/* Define if stropts.h does not define t_scalar_t. */
/* #undef NEED_T_SCALAR_T */

/* Define if stropts.h defines t_uscalar_t. */
#define t_uscalar_t t_uscalar_t

/* Define if stropts.h does not define t_uscalar_t. */
/* #undef NEED_T_USCALAR_T */

/* Define if timod supports TI_GETINFO.
   This ioctl goes all the way back to System V Release 3.0.
   If you do not have one, timod is unusable.
   Unfortunately, this could be 2 (OSF), 100 (SVR3) or 140 (SVR4).
 */
#define HAVE_TI_GETINFO 1

/* Define if timod supports TI_OPTMGMT.
   This ioctl goes all the way back to System V Release 3.0.
   If you do not have one, timod is unusable.
   Unfortunately, this could be 3 (OSF), 101 (SVR3) or 141 (SVR4).
 */
#define HAVE_TI_OPTMGMT 1

/* Define if timod supports TI_BIND.
   This ioctl goes all the way back to System V Release 3.0.
   If you do not have one, timod is unusable.
   Unfortunately, this could be 1 (OSF), 102 (SVR3) or 142 (SVR4).
 */
#define HAVE_TI_BIND 1

/* Define if timod supports TI_UNBIND.
   This ioctl goes all the way back to System V Release 3.0.
   If you do not have one, timod is unusable.
   Unfortunately, this could be 4 (OSF), 103 (SVR3) or 143 (SVR4).
 */
#define HAVE_TI_UNBIND 1

/* Define if timod supports TI_GETMYNAME.
   This is an System V Release 4 symbols that also provides socket library support.
 */
/* #undef HAVE_TI_GETMYNAME */

/* Define if timod supports TI_GETPEERNAME.
   This is an System V Release 4 symbols that also provides socket library support.
 */
/* #undef HAVE_TI_GETPEERNAME */

/* Define if timod supports TI_SETMYNAME.
   This is an System V Release 4 symbols that also provides socket library support.
 */
/* #undef HAVE_TI_SETMYNAME */

/* Define if timod supports TI_SETPEERNAME.
   This is an System V Release 4 symbols that also provides socket library support.
 */
/* #undef HAVE_TI_SETPEERNAME */

/* Define if timod supports TI_XTI_HELLO.
   This is an OSF-specific ioctl.
   Only define this if this is also an OSF derived operating system.
 */
/* #undef HAVE_TI_XTI_HELLO */

/* Define if timod supports TI_XTI_GET_STATE.
   This is an OSF-specific ioctl.
   Only define this if this is also an OSF derived operating system.
 */
/* #undef HAVE_TI_XTI_GET_STATE */

/* Define if timod supports TI_XTI_CLEAR_EVENT.
   This is an OSF-specific ioctl.
   Only define this if this is also an OSF derived operating system.
 */
/* #undef HAVE_TI_XTI_CLEAR_EVENT */

/* Define if timod supports TI_XTI_MODE.
   This is an OSF-specific ioctl.
   Only define this if this is also an OSF derived operating system.
 */
/* #undef HAVE_TI_XTI_MODE */

/* Define if timod supports TI_TLI_MODE.
   This is an OSF-specific ioctl.
   Only define this if this is also an OSF derived operating system.
 */
/* #undef HAVE_TI_TLI_MODE */

/* Define if timod supports TI_SYNC.
   This is an System V Release 4.2 XNS 5.2 XTI (SUSv1 and SUSv2) supporint io control.
 */
/* #undef HAVE_TI_SYNC */

/* Define if timod supports TI_GETADDRS.
   This is an System V Release 4.2 XNS 5.2 XTI (SUSv1 and SUSv2) supporint io control.
 */
/* #undef HAVE_TI_GETADDRS */

/* Define if timod supports TI_CAPABILITY.
   This is an System V Release 4.2 XNS 5.2 XTI (SUSv1 and SUSv2) supporint io control.
 */
/* #undef HAVE_TI_CAPABILITY */

/* Define if tihdr supports T_ORDREL_REQ/IND.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
#define HAVE_T_ORDREL 1

/* Define if tihdr supports T_ADDR_REQ/ACK.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
#define HAVE_T_ADDR 1

/* Define if tihdr supports T_CAPABILITY_REQ/ACK.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
#define HAVE_T_CAPABILITY 1

/* Define if tihdr supports T_OPTDATA_REQ/IND.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
#define HAVE_T_OPTDATA 1

/* Define if tihdr defines T_OPTDATA_REQ/IND but does not provide T_ODF_ flags.
   These flags are required to use T_OPTDATA_REQ/T_OPTDATA_IND DATA_flag field.
   LiS has broken tihdr.h header file, so we need this for most LiS releases.
 */
#define NEED_T_ODF_FLAGS 1

/* Define if tidhr defines T_optdata_ack and optdata_ack instead of optdata_ind.
   The standard is optdata_ind, but most LiS releases have broken tihdr.h files.
   LiS has broken tihdr.h header file, so we need this for most LiS releases.
 */
/* #undef HAVE_BROKEN_OPTDATA_ACK */

/* Define if tihdr supports T_GETADDR_REQ/ACK.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
/* #undef HAVE_T_GETADDR */

/* Define if tihdr supports T_FEEDBACK_REQ.
   This ioctl is not supported by all TI systems.
   If you do not have one, XTI will be unusable.
 */
/* #undef HAVE_T_FEEDBACK */

/* Define to get GNU extensions. */
#define _GNU_SOURCE 1

/* Define if libpthread has pthread_cleanup_push_defer_np. */
#define HAVE_PTHREAD_CLEANUP_POP_RESTORE 1

/* Define if libpthread has pthread_cleanup_push_defer_np. */
#define HAVE_PTHREAD_CLEANUP_POP_RESTORE 1

/* Define if you have libpthread (-lpthread). */
#define HAVE_LIB_PTHREAD 1

/* Define if libpthread has pthread_cleanup_push_defer_np. */
/* #undef HAVE_PTHREAD_CLEANUP_PUSH_DEFER */

/* Define if libpthread has pthread_cleanup_pop_restore_np. */
#define HAVE_PTHREAD_CLEANUP_POP_RESTORE 1

/* Define if you have libstreams (-lstreams). */
/* #undef HAVE_LIB_STREAMS */

/* Define if you have libLiS (-lLiS). */
#define HAVE_LIB_LIS 1

/* Define if unistd.h defines _SC_T_IOV_MAX. */
/* #undef NEED__SC_T_IOV_MAX */


/*****************************************************************************
 BEGINNING OF SEPARATE COPYRIGHT MATERIAL vim: ft=c
 *****************************************************************************

 @(#) config.h,v LiS-2_16_18-9(1.1.4.1) 2004/01/12 23:44:49

 -----------------------------------------------------------------------------

 Copyright (c) 2001-2004  OpenSS7 Corporation <http://www.openss7.com>
 Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 details.

 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 Ave, Cambridge, MA 02139, USA.

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

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 -----------------------------------------------------------------------------

 Last Modified 2004/01/12 23:44:49 by brian

 *****************************************************************************/

/*
 *  These are my header declarations after autoconf.
 */

#ident "@(#) config.h,v LiS-2_16_18-9(1.1.4.1) 2004/01/12 23:44:49"

/**
 * \defgroup libxti OpenSS7 XTI Library
 * \brief OpenSS7 XNS/XTI Library Calls
 *
 * This manpage contains documentation of OpenSS7 XTI Library functions that
 * are generated automatically from the source code with doxygen.  This
 * documentation is intended to be used for maintainers of the OpenSS7 XTI
 * Library and is not intended for users of the OpenSS7 XTI Library.  Users
 * should consult the documentation found in xti(3).
 *
 * \author Brian F. G. Bidulock
 * \version \LiS-2_16_18-9(\1.1.4.1)
 * \date \2004/01/12 23:44:49
 */

#define _XOPEN_SOURCE 1

#include <sys/types.h>

#ifndef NEED__SC_T_IOV_MAX
#include <unistd.h>
#else
#define _SC_T_IOV_MAX		1
#endif
#define _SC_T_DEFAULT_ADDRLEN	2
#define _SC_T_DEFAULT_CONNLEN	3
#define _SC_T_DEFAULT_DISCLEN	4
#define _SC_T_DEFAULT_OPTLEN	5
#define _SC_T_DEFAULT_DATALEN	6

#if defined(HAVE_STROPTS_H)
#include <stropts.h>
#elif defined(HAVE_SYS_STROPTS_H)
#include <sys/stropts.h>
#elif defined(HAVE_LINUX_STROPTS_H)
#include <linux/stropts.h>
#else
#include <stropts.h>
#endif

/*
   LiS incorrectly defines struct t_opthdr in tihdr.h 
 */
#ifdef __LINUX_WITH_LIS__
#define t_opthdr __unusable_t_opthdr
#endif

#if defined(HAVE_TIHDR_H)
#include <tihdr.h>
#elif defined(HAVE_SYS_TIHDR_H)
#include <sys/tihdr.h>
#elif defined(HAVE_LINUX_TIHDR_H)
#include <linux/tihdr.h>
#else
#include <sys/tihdr.h>
#endif

/*
   LiS incorrectly defines T_OPTDATA_REQ/IND without T_ODF_EX/MORE 
 */
#if defined NEED_T_ODF_FLAGS
#if !defined T_ODF_MORE
#define T_ODF_MORE		0x0001
#endif
#if !defined T_ODF_EX
#define T_ODF_EX		0x0002
#endif
#endif

/*
   LiS has broken T_optdata_ack and optdata_ack instead of T_optdata_ind and optdata_ind. 
 */
#if defined HAVE_BROKEN_OPTDATA_ACK
#define T_optdata_ind T_optdata_ack
#define optdata_ind optdata_ack
#endif				/* defined HAVE_BROKEN_OPTDATA_ACK */

#if defined(HAVE_TIMOD_H)
#include <timod.h>
#elif defined(HAVE_SYS_TIMOD_H)
#include <sys/timod.h>
#elif defined(HAVE_LINUX_TIMOD_H)
#include <linux/timod.h>
#else
#include <sys/timod.h>
#endif

#include <xti/xti.h>

#define _T_DEFAULT_ADDRLEN	128
#define _T_DEFAULT_CONNLEN	256
#define _T_DEFAULT_DISCLEN	256
#define _T_DEFAULT_OPTLEN	256
#define _T_DEFAULT_DATALEN	1024
#define _T_TIMEOUT		-1
#define _T_IOV_MAX		16

extern struct t_info *fds[];

#if 0
extern int _t_ioctl(int fd, int cmd, void *arg);
extern int _t_strioctl(int fd, int cmd, void *arg, size_t arglen);
extern int _t_putmsg(int fd, struct strbuf *ctrl, struct strbuf *data, int flags);
extern int _t_getmsg(int fd, struct strbuf *ctrl, struct strbuf *data, int *flags);
extern int _t_rcvconnect(int fd, struct t_call *call, struct t_info *info);
extern int _t_getinfo(int fd, struct t_info *info);

typeof(_t_ioctl)
	__xnet__t_ioctl __attribute__ ((__weak__, __alias__("_t_ioctl")));
typeof(_t_strioctl)
	__xnet__t_strioctl __attribute__ ((__weak__, __alias__("_t_strioctl")));
typeof(_t_putmsg)
	__xnet__t_putmsg __attribute__ ((__weak__, __alias__("_t_putmsg")));
typeof(_t_getmsg)
	__xnet__t_getmsg __attribute__ ((__weak__, __alias__("_t_getmsg")));
typeof(_t_rcvconnect)
	__xnet__t_rcvconnect __attribute__ ((__weak__, __alias__("_t_rcvconnect")));
typeof(_t_getinfo)
	__xnet__t_getinfo __attribute__ ((__weak__, __alias__("_t_getinfo")));
#endif

#if defined __LINUX_WITH_LIS__ && !defined HAVE_LIB_LIS
#pragma weak getpmsg
#pragma weak putpmsg
#pragma weak getmsg
#pragma weak putmsg
#endif				/* defined __LINUX_WITH_LIS__ && !defined HAVE_LIB_LIS */

#if (defined __LINUX_WITH_LIS__ && !defined HAVE_LIB_LIS) || \
    (defined __LINUX_WITH_LFS__ && !defined HAVE_LIB_STREAMS)
#pragma weak isastream
#endif				/* (defined __LINUX_WITH_LIS__ && !defined HAVE_LIB_LIS) ||
				   (defined __LINUX_WITH_LFS__ && !defined HAVE_LIB_STREAMS) */

/*****************************************************************************

 Copyright (c) 2001-2004  OpenSS7 Corporation <http://www.openss7.com>
 Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>

 *****************************************************************************
 ENDING OF SEPARATE COPYRIGHT MATERIAL vim: ft=c
 *****************************************************************************/
