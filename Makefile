# Makefile -- build script for luhn algorithm program.
# Author: Luis Colorado <luiscoloradourcola@gmail.com>
# Date: Fri Feb 17 09:21:36 AM EET 2023
# Copyright: (C) 2023 Luis Colorado.  All rights reserved.
# License: BSD.

targets = luhn luhn_rl
toclean = $(targets)
RM ?= rm -f

all: $(targets)
clean:
	$(RM) $(toclean)

luhn_objs = luhn.o
luhn_deps =
luhn_ldfl = 
luhn_libs =
toclean += $(luhn_objs)

luhn_rl_objs = luhn_rl.o
luhn_rl_deps =
luhn_rl_ldfl =
luhn_rl_libs =
toclean += $(luhn_rl_objs)

luhn: $(luhn_deps) $(luhn_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_ldfl) $($@_objs) $($@_libs) $(LIBS)

luhn_rl: $(luhn_rl_deps) $(luhn_rl_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_ldfl) $($@_objs) $($@_libs) $(LIBS)
