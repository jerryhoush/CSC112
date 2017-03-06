#include "pixel.h"
#include <iostream>
#define GREEN  "\033[32m" 
#define RED    "\033[31m" 
#define BLUE   "\033[34m" 
#define NORM "\033[0m" 
using namespace std;

Pixel::Pixel(int r, int g, int b)
{
   if(r<=0)
      {r=0;}
   else if(r>=255)
      {r=255;}
   red_=r;
   if(g<=0)
      {g=0;}
   else if(g>=255)
      {g=255;}
   green_=g;
   if(b<=0)
      {b=0;}
   else if(b>=255)
      {b=255;}
   blue_=b;
}

bool Pixel::setRed(int r)
{
   if(r>0 && r<255)
   {
	red_=r;
	return true;
   }
   else 
   {
        if(r<=0)
        {r=0;}
        else if(r>=255)
        {r=255;}
        red_=r;
        return false;
   }
}

bool Pixel::setGreen(int g)
{
   if(g>0 && g<255)
   {
	green_=g;
	return true;
   }
   else 
   {
        if(g<=0)
        {g=0;}
        else if(g>=255)
        {g=255;}
        green_=g;
	return false;
   }
}

bool Pixel::setBlue(int b)
{
   if(b>0 && b<255)
   {
	blue_=b;
	return true;
   }
   else
   {
	if(b<=0)
        {b=0;}
        else if(b>=255)
        {b=255;}
        blue_=b;
	return false;
   }
}

unsigned char Pixel::grayscale()const
{
   return ((0.2989*red_) + (0.5870*green_) + (0.1140*blue_));
}


bool Pixel::operator==(const Pixel& rhs)
{
   if(red_==rhs.red_ && green_==rhs.green_ && blue_==rhs.blue_)
   {
	return true;
   }
   else
	return false;
}

bool Pixel::operator!=(const Pixel& rhs)
{
   if(red_!=rhs.red_ || green_!=rhs.green_ || blue_!=rhs.blue_)
   {
	return true;
   }
   else
	return false;
}

Pixel Pixel::operator+(const Pixel& rhs)
{
   Pixel result;
   if((int)red_+(int)rhs.red_>255)
	{result.red_=255;}
   else
	{result.red_=red_+rhs.red_;}

   if((int)green_+(int)rhs.green_>255)
	{result.green_=255;}
   else
	{result.green_=green_+rhs.green_;}
   
   if((int)blue_+(int)rhs.blue_>255)
	{result.blue_=255;}
   else
	{result.blue_=blue_+rhs.blue_;}
   return result;
}

ostream& operator<<(ostream& out, const Pixel& rhs)
{
out<<"["<<RED<<(int)rhs.red_<<NORM<<","<<GREEN<<(int)rhs.green_<<NORM<<","<<BLUE<<(int)rhs.blue_<<NORM<<"]";
return out;
}











