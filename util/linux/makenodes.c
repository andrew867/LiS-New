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

int main( int argc, char *argv[] )
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
	(void)unlink("/dev/mux_clone");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/mux_clone", 020666, makedevice(231,235)) ;
	    if (rslt < 0) printf("/dev/mux_clone: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/minimux.1");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/minimux.1", 020666, makedevice(235,1)) ;
	    if (rslt < 0) printf("/dev/minimux.1: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/minimux.2");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/minimux.2", 020666, makedevice(235,2)) ;
	    if (rslt < 0) printf("/dev/minimux.2: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/clone_drvr");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/clone_drvr", 020666, makedevice(231,0)) ;
	    if (rslt < 0) printf("/dev/clone_drvr: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/ldl");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/ldl", 020666, makedevice(231,237)) ;
	    if (rslt < 0) printf("/dev/ldl: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/printk");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/printk", 020666, makedevice(236,0)) ;
	    if (rslt < 0) printf("/dev/printk: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/sad");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/sad", 020666, makedevice(231,238)) ;
	    if (rslt < 0) printf("/dev/sad: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/fifo");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/fifo", 020666, makedevice(231,232)) ;
	    if (rslt < 0) printf("/dev/fifo: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	(void)unlink("/dev/fifo.0");
#endif
	if (!rmopt)
	{
	    rslt = mknod("/dev/fifo.0", 020666, makedevice(232,0)) ;
	    if (rslt < 0) printf("/dev/fifo.0: %s\n", strerror(-rslt));
	}

#if !defined(USER)
	exit(0);
#else
	return(0);
#endif
}
