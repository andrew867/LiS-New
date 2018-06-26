/*****************************************************************************

 @(#) xti_tcp.h,v 1.1.4.1 2004/01/12 23:44:52 brian Exp

 -----------------------------------------------------------------------------

     Copyright (C) 1997-2004 OpenSS7 Corporation.  All Rights Reserved.

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

 Last Modified 2004/01/12 23:44:52 by brian

 *****************************************************************************/

#ifndef __XTI_TCP_H__
#define __XTI_TCP_H__

#ident "@(#) xti_tcp.h,v LiS-2_16_18-9(1.1.4.1) Copyright (c) 1997-2004 OpenSS7 Corporation."

#ifdef __BEGIN_DECLS
/* *INDENT-OFF* */
__BEGIN_DECLS
/* *INDENT-ON* */
#endif

/*
 * TCP level
 */
#define T_INET_TCP		6	/* TCP level (same as protocol number) */

/*
 * TCP level Options
 */
#define T_TCP_NODELAY		1	/* don't coalese packets */
#define T_TCP_MAXSEG		2	/* get maximum segment size */
#define T_TCP_KEEPALIVE		3	/* keep connections alive */

/* 
 * Structure used with TCP_KEEPALIVE option.
 */
struct t_kpalive {
	t_scalar_t kp_onoff;		/* option on/off */
	t_scalar_t kp_timeout;		/* timeout in minutes */
};

#ifdef __END_DECLS
/* *INDENT-OFF* */
__END_DECLS
/* *INDENT-ON* */
#endif

#endif				/* __XTI_TCP_H__ */
