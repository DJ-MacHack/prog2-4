CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=main.cpp Lager.cpp Lager.h Lagerdialog.cpp Lagerdialog.h Artikel.cpp Artikel.h Artikeldialog.cpp Artikeldialog.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: Lager
Lager: main.o Lager.o Artikel.o Artikeldialog.o Lagerdialog.o
	$(CXX) $(CPPFLAGS) -o lager main.o Lager.o Artikel.o Artikeldialog.o Lagerdialog.o
main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp
Lager.o: Lager.cpp Lager.h
	$(CXX) $(CPPFLAGS) -c Lager.cpp Lager.h
Lagerdialog.o: Lagerdialog.cpp Lagerdialog.h
	$(CXX) $(CPPFLAGS) -c Lagerdialog.cpp Lagerdialog.h
Artikeldialog.o: Artikeldialog.cpp Artikeldialog.h
	$(CXX) $(CPPFLAGS) -c Artikeldialog.cpp Artikeldialog.h
Artikel.o: Artikel.cpp Artikel.h
	$(CXX) $(CPPFLAGS) -c Artikel.cpp Artikel.h

.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch
