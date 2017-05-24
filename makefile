CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=main.cpp Lager.cpp Lager.h Lagerdialog.cpp Lagerdialog.h Artikel.cpp Artikel.h Artikeldialog.cpp Artikeldialog.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: Lager
Lager: Lager.o Artikel.o Artikeldialog.o Lagerdialog.o
	$(CXX) $(CPPFLAGS) -o lager Lager.o Artikel.o Artikeldialog.o Lagerdialog.o
Lager.o: Lager.cpp Lager.h
	$(CXX) $(CPPFLAGS) -c main.cpp
Lagerdialog.o: Lagerdialog.cpp Lagerdialog.h
	$(CXX) $(CPPFLAGS) -c Lagerdialog.cpp Lagerdialog.h
Artikeldialog.o: Artikeldialog.cpp Artikeldialog.h
	$(CXX) $(CPPFLAGS) -c Artikeldialog.cpp Artikeldialog.h
Artikel.o: Artikel.cpp Artikel.h
	$(CXX) $(CPPFLAGS) -c Artikel.cpp Artikel.h

.PHONY: clean
clean:
	rm -f arraytest *.o

.PHONY: clear
clear:
	rm -f *.o
