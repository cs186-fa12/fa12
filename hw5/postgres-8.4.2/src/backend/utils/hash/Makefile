#-------------------------------------------------------------------------
#
# Makefile--
#    Makefile for utils/hash
#
# IDENTIFICATION
#    $PostgreSQL: pgsql/src/backend/utils/hash/Makefile,v 1.13 2008/02/19 10:30:08 petere Exp $
#
#-------------------------------------------------------------------------

subdir = src/backend/utils/hash
top_builddir = ../../../..
include_dir = ../../../include
include $(top_builddir)/src/Makefile.global

OBJS = dynahash.o hashfn.o pg_crc.o cmsketch.o

include $(top_srcdir)/src/backend/common.mk

# CountMin Sketch test
cmsketch_test: cmsketch_test.c cmsketch.c
	$(CC) $(CFLAGS) -DTESTING -I$(include_dir) $(LDFLAGS) $(export_dynamic) $^ $(LIBS) -o $@

distclean clean:
	rm -f cmsketch_test cmsketch_test.o 
