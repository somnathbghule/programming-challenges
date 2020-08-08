#LDFLAGS for loader flags; EXTRA_CFLAGS for file inclusion
#LDADD for linking and loading the library
SRCS= ./IOPipeline.cpp 
PROG=programming-challenges
CFLAGS=-g -Wall -I.
CC= g++
include /usr/lib/build/linux.prog.mk
