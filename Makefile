#Makefile for "histograma" C++application
#Created by Luís Eduardo Rique

PROG = histograma

SRCPATH = src/
BINPATH = bin/
BUILDPATH = build/
INCLUDEPATH = include/

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I$(INCLUDEPATH)
CC = g++

OBJS = $(BUILDPATH)main.o $(BUILDPATH)calcArea.o $(BUILDPATH)area.o $(BUILDPATH)calcPerimetro.o $(BUILDPATH)perimetro.o $(BUILDPATH)calcVolume.o $(BUILDPATH)volume.o 

$(PROG) : $(OBJS)
	$(CC) -o $(BINPATH)$(PROG) $(OBJS)

$(BUILDPATH)main.o : $(INCLUDEPATH)calcArea.h $(INCLUDEPATH)calcPerimetro.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)main.cpp -o $@

$(BUILDPATH)calcArea.o : $(INCLUDEPATH)calcArea.h $(INCLUDEPATH)area.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)calcArea.cpp -o $@

$(BUILDPATH)area.o : $(INCLUDEPATH)area.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)area.cpp -o $@

$(BUILDPATH)calcPerimetro.o : $(INCLUDEPATH)calcPerimetro.h $(INCLUDEPATH)perimetro.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)calcPerimetro.cpp -o $@

$(BUILDPATH)perimetro.o : $(INCLUDEPATH)perimetro.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)perimetro.cpp -o $@

$(BUILDPATH)calcVolume.o : $(INCLUDEPATH)calcVolume.h $(INCLUDEPATH)volume.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)calcVolume.cpp -o $@

$(BUILDPATH)volume.o : $(INCLUDEPATH)volume.h
	$(CC) $(CPPFLAGS) -c $(SRCPATH)volume.cpp -o $@

clean :
rm -f core $(BINPATH)$(PROG) $(OBJS)
