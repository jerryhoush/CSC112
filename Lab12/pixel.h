#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
using namespace std;

class Pixel
{
   public:
	   Pixel(int r=255, int g=255, int b=255);
	   unsigned char red()const{return red_;}
	   unsigned char green()const{return green_;}
	   unsigned char blue()const{return blue_;}
	   bool setRed(int r);
	   bool setGreen(int g);
	   bool setBlue(int b);
	   unsigned char grayscale()const;
	   bool operator==(const Pixel& rhs);
	   bool operator!=(const Pixel& rhs);
	   Pixel operator+(const Pixel& rhs);
	   friend ostream& operator<<(ostream& out, const Pixel& rhs);
	   friend class PixelLinkList;



   private:
	   unsigned char red_;
	   unsigned char green_;
	   unsigned char blue_;
};

#endif
