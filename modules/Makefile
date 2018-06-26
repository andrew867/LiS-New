Makefile_ident="@(#) LiS modules/Makefile 1.3 09/09/04"

include .config_mk

default: modules 
	$(nothing)

HERE	= $(shell pwd)
SD	= marshall/
$(shell mkdir -p $(SD))

#
# List of modules consists of anything left behind in the various
# build directories plus anything that was been copied into this directory.
#
MODULES   := $(shell find $(SRCDIR) -name .modules -exec cat {} \;)
MODULES   += $(addprefix modules/,$(wildcard *.o))
#
# All of the object code files for modules with full pathnames
#
obj-m := $(addprefix $(HERE)/$(SD),$(notdir $(MODULES)))

# construct the old hardcoded dest directory, for comparison
#
OLD_INST_DIR = $(dir $(MOD_INST_DIR:%/=%))misc

#
# so that a make install does the same thing as make modules_install
#
install:	modules_install

ifneq ($(KBUILD),y)		############################## !KBUILD

RECURSIVE_MAKE	=

#
# default module subdir may have changed from .../misc - if so,
# we'll remove old modules
#
ifneq ($(MOD_INST_DIR),$(OLD_INST_DIR))
ifeq ($(DESTDIR),)
OLD_MODULES = $(wildcard $(addprefix $(OLD_INST_DIR)/,$(notdir $(MODULES))))
endif
endif

modules_install: $(obj-m)
ifneq ($(MOD_INST_DIR),$(OLD_INST_DIR))
ifneq ($(OLD_MODULES),)
	-$(Q)rm -f $(OLD_MODULES)
endif
endif
	$(Q_ECHO) $(qtag_INSTALL)"[modules]" $(relpwd)
	$(Q)install -d $(DESTDIR)$(MOD_INST_DIR)
	$(Q)install $(obj-m) $(MOD_INST_DIR)/.
#	symlink to the installed modules directory
	$(Q)install -d $(DESTDIR)$(pkgdatadir)/linux-$(KVER)
	$(Q)(cd $(DESTDIR)$(pkgdatadir)/linux-$(KVER) && \
		$(LN) $(MOD_INST_DIR) modules && rm -f modules/misc)


else	##################################### !KBUILD


RECURSIVE_MAKE	= $(Q)make -f Makefile.2.6 KSRC=$(KSRC) KBIN=$(KBIN) SD=$(SD) V=$(V)
$(shell mkdir -p scripts/mod $(SD) $(SD)/scripts)

#
# default module subdir may have changed from .../misc - if so,
# we'll remove old modules
#
ifneq ($(MOD_INST_DIR),$(OLD_INST_DIR))
ifeq ($(DESTDIR),)
OLD_MODULES = $(wildcard $(addprefix $(OLD_INST_DIR)/,$(notdir $(MODULES:.o=.ko))))
endif
endif

# we make modules_install depend on the .ko files that result from the
# 'modules' target instead of the 'modules' target itself, to avoid
# remaking them if they already exist
#
modules_install: $(obj-m:.o=.ko)
ifneq ($(MOD_INST_DIR),$(OLD_INST_DIR))
ifeq ($(DESTDIR),)
ifneq ($(OLD_MODULES),)
	-$(Q)rm -f $(OLD_MODULES)
endif
endif
endif
	$(Q_ECHO) $(qtag_INSTALL)"[modules]" $(relpwd)
	$(Q)install -d $(DESTDIR)$(MOD_INST_DIR)
	$(Q)install $(obj-m:.o=.ko) $(DESTDIR)$(MOD_INST_DIR)/.
#	symlink to the installed modules directory
	$(Q)install -d $(DESTDIR)$(pkgdatadir)/linux-$(KVER)
	$(Q)(cd $(DESTDIR)$(pkgdatadir)/linux-$(KVER) && \
		$(LN) $(MOD_INST_DIR) modules && rm -f modules/misc)

endif	#################################### KBUILD


#
# the following just makes the input .o files local.  It can either copy
# them, or symlink to them
#
# For 2.6 we then invoke a "recursive" make to process all the files
#
modules: FORCE
	$(Q)cp $(addprefix $(SRCDIR)/,$(MODULES)) $(SD)
	$(RECURSIVE_MAKE)

clean:
	$(Q_ECHO) $(qtag_CLEAN)$(relpwd)
	-$(Q)rm -f *.ko *.o *.mod.o *.mod.c ./.*.cmd *symvers
	-$(Q)rm -rf .tmp_versions $(SD) scripts

FORCE:
