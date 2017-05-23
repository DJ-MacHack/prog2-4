CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=ArrayTest.cpp ArrayTools.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: ArrayTest
ArrayTest: ArrayTest.o
	$(CXX) $(CPPFLAGS) -o arraytest ArrayTest.o
ArrayTest.o: ArrayTest.cpp ArrayTools.h
	$(CXX) $(CPPFLAGS) -c ArrayTest.cpp



.PHONY: clean
clean:
	rm -f arraytest *.o

.PHONY: clear
clear:
	rm -f *.o
