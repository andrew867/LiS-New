include .config_mk

PRELDOBJS = getpmsg.o getmsg.o putpmsg.o putmsg.o \
	  fattach.o fdetach.o isastream.o # mknod.o poll.o

LIBOBJS = $(PRELDOBJS) pipe.o

CP_OPTS	= -f
XOPTS  += -D__KERNEL_SYSCALLS__

ifeq ($(ARCH), s390x)
#
# For 64-bit zSeries, specify use of position independent code
XOPTS  += -fPIC
endif
# For 64-bit ppc64, specify use of position independent code
ifeq ($(ARCH), ppc64)
XOPTS  += -fPIC -m64
endif
# For 64-bit x86_64, specify use of position independent code
ifeq ($(ARCH), x86_64)
XOPTS  += -m64 -fPIC
endif



include $(LIBDIR)/mk.bdy


#
# Dependency stuff
#

-include .depend

dep:
	$(Q_ECHO) $(qtag_DEP)$(relpwd)
	$(Q)$(CC) -M -DDEP $(LIBOBJS:%.o=$(LIBDIR)/%.c) >.depend

