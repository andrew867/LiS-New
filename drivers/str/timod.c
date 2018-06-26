/*
 *  timod module.
 *
 *  Version: 0.2
 *
 *  Copyright (C) 1998 Ole Husgaard (sparre@login.dknet.dk)
 *
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Cambridge,
 * MA 02139, USA.
 *
 */

#ident "@(#) LiS timod.c 2.14 09/13/04 10:12:31 "

#include <sys/LiS/module.h>	/* must be VERY first include */

#ifdef MODULE

#ifdef KERNEL_2_5
int timod_init_module(void)
#else
int init_module(void)
#endif
{
	printk("timod.init_module:\n");
	return 0;
}

#ifdef KERNEL_2_5
void timod_cleanup_module(void)
#else
void cleanup_module(void)
#endif
{
	printk("timod.cleanup_module: in");
	return;
}

#ifdef KERNEL_2_5
module_init(timod_init_module) ;
module_exit(timod_cleanup_module) ;
#endif

#if defined(LINUX)			/* linux kernel */
#if defined(MODULE_LICENSE)
MODULE_LICENSE("GPL and additional rights");
#endif
#if defined(MODULE_AUTHOR)
MODULE_AUTHOR("Ole Husgaard (sparre@login.dknet.dk");
#endif
#if defined(MODULE_DESCRIPTION)
MODULE_DESCRIPTION("STREAMS timod module, converts ioctls to TLI");
#endif
#endif					/* LINUX */

#endif					/* MODULE */
