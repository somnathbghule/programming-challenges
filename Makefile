#LDFLAGS for loader flags; EXTRA_CFLAGS for file inclusion
#LDADD for linking and loading the library
SRCS=./02_08_05_StackThemUp.cpp ./02_08_01_JollyJumper.cpp ./2_8_6_ErdosNumbers.cpp ./IOPipeline.cpp 
PROG=programming-challenges
CFLAGS=-g -Wall -I.
CC= g++
include /usr/lib/build/linux.prog.mk
