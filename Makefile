CC=gcc
PKG_CONFIG=pkg-config
CFLAGS := $(shell getconf LFS_CFLAGS) -Wall -Wno-unused-result -O2 -g $(shell $(PKG_CONFIG) --cflags)
LDLIBS=$(shell $(PKG_CONFIG))

casperhost-name: casperhost-name.c

clean:
	rm -f *.o casperhost-name

