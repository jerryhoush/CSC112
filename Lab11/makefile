# Programmer: Jerry Housh	Course: CSC112

# Assignment: lab11	  	Date: 04/21/2014

CC = g++
CFLAGS = -g -pg -Wall

lab11: driver.o pixellist1.o pixellist2.o pixel.o
	$(CC) $(CFLAGS) -o lab11 driver.o pixellist1.o pixellist2.o pixel.o
driver.o: driver.cpp pixellist.h
	$(CC) $(CFLAGS) -c driver.cpp
pixellist1.o: pixellist1.cpp pixellist.h
	$(CC) $(CFLAGS) -c pixellist1.cpp
pixellist2.o: pixellist2.cpp pixellist.h
	$(CC) $(CFLAGS) -c pixellist2.cpp
pixel.o: pixel.cpp pixel.h
	$(CC) $(CFLAGS) -c pixel.cpp
clean:
	\rm -f *.o main
