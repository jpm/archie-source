# archie Version 3.5-beta
# Bunyip Information Systems, 1994
# $Id: Makefile,v 1.10 1995/03/17 13:50:36 pedro Exp $
#
# This is the configuration Makefile for the archie V 3.5 distribution
# 
# Change the following 2 definitions if you don't like the defaults MAKE
# SURE that you have allocated the archie user codes before running this
# Makefile The name of the archie administrative code. You might want to
# create an archie group as well
# 
# YOU MUST RUN THIS MAKEFILE AS SUPERUSER
#

ARCHUSER=archie
ARCHGRP =archie

# The place for the manpages describing the binaries

MANEXT=n
MAN=../man

#MAN5EXT=$(MANEXT)
MAN5EXT=5
MAN5=$(MAN)/man${MAN5EXT}

# Default permissions for archie binaries

AR_PERMS=711
ARS_PERMS=755

all: su links manpages owners archieb pfs links


su:
	@echo "Making sure you're superuser"
	@id=`id | sed 's/(.*$$//' | sed 's/^.*=//'`; \
	echo "Your uid is $$id"; \
	if [ "$$id" -ne "0" ]; then \
		echo "You must be running as superuser to configure archie"; \
		exit 2;\
	fi

owners:
	@echo Changing ownership to the archie user: $(ARCHUSER)
	(cd ..; chown -R $(ARCHUSER) *; chgrp -R $(ARCHGRP) *;\
		chown $(ARCHUSER) . ; chgrp $(ARCHGRP) .; \
		chown $(ARCHUSER) .*; chgrp $(ARCHGRP) .*; chmod 755 .)

archieb:
	@echo Copying the shell and perl scripts into the bin directory
	(cd ../scripts; tar cf - . | gzip > /tmp/scripts.tgz ; cd ../bin ;\
		../scripts/untar /tmp/scripts.tgz)
	@echo Setting permissions for binaries
	for i in `find ../bin -type f -print | grep -v CVS | \
			 sed 's?../bin/??g'`; do\
		chmod $(AR_PERMS) ../bin/$$i;\
	done
	@echo Setting permissions for scripts
	cd ../bin; /bin/file ./* | egrep -v '(demand|link|directory)' | \
		sed 's?:.*$$??' | xargs -t chmod $(ARS_PERMS)
	@echo Setting permissions for logs
	chmod 662 ../logs/email.log
	@echo Setting permissions for tmp directory
	chmod 1777 ../db/tmp ../tmp
	@echo Taking care of the pager
	cp ../bin/less* ../pager/bin
	chmod 555 ../pager/bin/less*
	@echo Setting permissions for telnet client and email
	chown root ../bin/telnet-client
	chmod 111 ../bin/telnet-client
	chmod u+s ../bin/telnet-client
	chmod 755 ../bin ../etc ../logs
	chmod 644 ../etc/*
	chmod g+s ../bin/email-client
	@echo Setting permissions for cgi progs
	chmod 755 ../cgi ../cgi/*
	chmod 644 ../cgi/html/*
	chmod 755 ../cgi/bin/archie.cgi
	chmod 755 ../cgi/bin/cgi-client
	chmod u+s ../cgi/bin/cgi-client
	chmod 755 ../stats
	@echo Setting permissions for databases
	chmod a+rx ../db ../db/* ../db/*/start_db

manpages:
	-mkdir $(MAN) && chmod 755 $(MAN)
	-mkdir $(MAN)/manent
	chmod 111 ../bin/telnet-client
	chmod u+s ../bin/telnet-client
	chmod 755 ../bin ../etc ../logs
	chmod 644 ../etc/*
	chmod g+s ../bin/email-client
	@echo Setting permissions for cgi progs
	chmod 755 ../cgi ../cgi/*
	chmod 644 ../cgi/html/*
	chmod 755 ../cgi/bin/archie.cgi
	chmod 755 ../cgi/bin/cgi-client
	chmod u+s ../cgi/bin/cgi-client
	@echo Setting permissions for databases
	chmod a+rx ../db ../db/* ../db/*/start_db

manpages:
	-mkdir $(MAN) && chmod 755 $(MAN)
	-mkdir $(MAN)/man$(MANEXT) && chmod 755 $(MAN)/man$(MANEXT)
	-mkdir $(MAN5) && chmod 755 $(MAN5)
	for i in `find ../manpages/*.n -type f -print | grep -v CVS |\
		 sed 's?../manpages/??g' | sed 's/\..$$//g'`; do\
		cp ../manpages/$$i.n $(MAN)/man$(MANEXT)/$$i.$(MANEXT);\
		chmod 644 $(MAN)/man$(MANEXT)/$$i.$(MANEXT);\
		if [ -f /usr/ucb/echo ] ; then  /usr/ucb/echo -n "." ; \
		else  echo -n "." ; fi \
	done 
	@echo ""
	for i in `find ../manpages/*.5 -type f -print | grep -v CVS |\
		 sed 's?../manpages/??g' | sed 's/\..$$//g'`; do\
		cp ../manpages/$$i.5 $(MAN5)/$$i.$(MAN5EXT);\
		chmod 644 $(MAN5)/$$i.$(MAN5EXT);\
		if [ -f /usr/ucb/echo ] ; then  /usr/ucb/echo -n "." ; \
		else  echo -n "." ; fi \
	done
	@echo ""
	@echo "Done";

pfs:
	@echo "Taking care of things in /pfs"
	find ../pfs -type f -print | xargs -t chmod 644
	find ../pfs -type d -print | xargs -t c