include .config_mk

OPT	= -DLINUX
ifeq ($(ARCH),ppc64)
	XUTILS  = ldlconfig test test2 fattach fdetach mkfifo thrtst
else
ifeq ($(ARCH),x86_64)
	XUTILS  = ldlconfig test test2 fattach fdetach mkfifo thrtst
else
	XUTILS  = ldltest ldlconfig test test2 fattach fdetach mkfifo thrtst
endif
endif

XINST	= install_xutils
XUNINST	= uninstall_xutils
XCLEAN	= makenodes.c
ULOPTS += -pthread

include $(UTILDIR)/mk.bdy

default:
	$(nothing)

#thrtst:	thrtst.c
#	$(CC) -o $@ $^ $(ULOPTS) -lpthread
	
#strtst:	../strtst.c
#	$(CC) -o $@ $^ $(ULOPTS) -lpthread
	
ifeq ($(ARCH),ppc64)
install_xutils:	ldlconfig fattach fdetach
else
ifeq ($(ARCH),x86_64)
install_xutils:	ldlconfig fattach fdetach
else
install_xutils:	ldltest ldlconfig fattach fdetach
endif
endif
	$(Q)install -d $(DESTDIR)$(sbindir)
	$(Q)install $^ $(DESTDIR)$(sbindir)

uninstall_xutils:
	-$(Q)(cd $(DESTDIR)$(sbindir) && \
		rm -f ldltest ldlconfig fattach fdetach)


#
## Dependency stuff
#

dep:
	$(nothing)
