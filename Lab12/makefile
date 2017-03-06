# Programmer: Jerry Housh	Course: CSC112

# Assignment: lab12	  	Date: 04/28/2014

CC = g++
CFLAGS = -g -pg -Wall

lab12: driver.o pixellinklist.o pixellist1.o pixellist2.o pixel.o
	$(CC) $(CFLAGS) -o lab12 driver.o pixellinklist.o pixellist1.o pixellist2.o pixel.o
driver.o: driver.cpp pixellinklist.h
	$(CC) $(CFLAGS) -c driver.cpp
pixellinklist.o: pixellinklist.h pixellinklist.cpp pixel.h pixellist.h pixelnode.h
	$(CC) $(CFLAGS) -c pixellinklist.cpp
pixellist1.o: pixellist1.cpp pixellist.h pixel.h
	$(CC) $(CFLAGS) -c pixellist1.cpp
pixellist2.o: pixellist2.cpp pixellist.h pixel.h
	$(CC) $(CFLAGS) -c pixellist2.cpp
pixel.o: pixel.cpp pixel.h
	$(CC) $(CFLAGS) -c pixel.cpp
clean:
	\rm -f *.o main
