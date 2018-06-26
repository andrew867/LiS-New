/* WARNING:  THIS FILE WAS GENERATED.  MANUAL CHANGES MAY BE LOST. */

#if defined(LINUX)
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <sys/sysmacros.h>
#  define makedevice(maj,min) makedev(maj,min)
#elif defined(QNX)
#  include <sys/types.h>
#  include <sys/stat.h>
#  define makedevice(maj,min) makedev(1,maj,min)
#elif defined(USER)
#  include <sys/stropts.h>
#  include <sys/LiS/usrio.h>
#else
#  include <sys/types.h>
#  include <sys/stat.h>
#  define makedevice(maj,min) makedev(maj,min)
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#if !defined(LINUX)
#  include <fcntl.h>
#endif

int make_nodes( int argc, char *argv[] )
{
	int	rslt ;
	int	rmopt = 0 ;
	char	*strerror(int) ;

#if !defined(USER)
	(void)umask(0);
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'r')
	    rmopt = 1 ;

#endif
#if !defined(USER)
	(void)unlink("loop.1");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("loop.1", 020644, makedevice(50,1)) ;
	    if (rslt < 0) printf("loop.1: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("loop.2");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("loop.2", 020666, makedevice(50,2)) ;
	    if (rslt < 0) printf("loop.2: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("loop.9");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("loop.9", 020666, makedevice(50,9)) ;
	    if (rslt < 0) printf("loop.9: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("loop.255");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("loop.255", 020666, makedevice(50,255)) ;
	    if (rslt < 0) printf("loop.255: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("loop_clone");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("loop_clone", 020666, makedevice(32,50)) ;
	    if (rslt < 0) printf("loop_clone: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("mux_clone");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("mux_clone", 020666, makedevice(32,51)) ;
	    if (rslt < 0) printf("mux_clone: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("minimux.1");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("minimux.1", 020666, makedevice(51,1)) ;
	    if (rslt < 0) printf("minimux.1: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("minimux.2");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("minimux.2", 020666, makedevice(51,2)) ;
	    if (rslt < 0) printf("minimux.2: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("clone_drvr");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("clone_drvr", 020666, makedevice(32,0)) ;
	    if (rslt < 0) printf("clone_drvr: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("printk");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("printk", 020666, makedevice(52,0)) ;
	    if (rslt < 0) printf("printk: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("sad");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("sad", 020666, makedevice(32,53)) ;
	    if (rslt < 0) printf("sad: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("fifo");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("fifo", 020666, makedevice(32,54)) ;
	    if (rslt < 0) printf("fifo: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("fifo.0");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("fifo.0", 020666, makedevice(54,0)) ;
	    if (rslt < 0) printf("fifo.0: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("putst");
#endif
	if (!rmopt)
	{
	    rslt = user_mknod("putst", 020666, makedevice(56,0)) ;
	    if (rslt < 0) printf("putst: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	exit(0);
#else
	return(0);
#endif
}
