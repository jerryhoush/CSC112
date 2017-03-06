#include "pixellist.h"
#include "pixel.h"
#include <iostream>

using namespace std;

/**
*
*@brief  The replace function, replaces oldPixel with newPixel
*
*@param  oldPixel is the Pixel being replaced
*
*@param  newPixel is the Pixel replacing oldPixel
*  
*/

void PixelList:: replace(Pixel oldPixel, Pixel newPixel)
{
   for(int i=0; i<size_; i++)
   {
	if(list_[i]==oldPixel)
	{
	   list_[i]=newPixel;
	}
   }
}

/**
*
*@brief  The brief function
*
*@param  first param
*
*@param  second param
*  
*/

PixelList operator+(const PixelList& lhs, const PixelList& rhs)
{
   PixelList result;
   if(lhs.size_>rhs.size_)
   {
	result=lhs;
	for(int i=0; i<rhs.size_; i++)
	{
	   result.list_[i]=result.list_[i]+rhs.list_[i];
	}
   }
   else
   {
	result=rhs;
	for(int i=0; i<lhs.size_; i++)
	{
	   result.list_[i]=result.list_[i]+lhs.list_[i];
	}
   }
   return result;
}

/**
*
*@brief  The replace function, 
*
*@param  first param
*
*@param  second param
*  
*/

bool operator==(const PixelList& lhs, const PixelList& rhs)
{
   if(lhs.size_!=rhs.size_)
   {
	return false;
   }
   for(int i=0; i<rhs.size_; i++)
   {
	if(lhs.list_[i]!=rhs.list_[i])
	{
	   return false;
	}
   }
   return true;
}

/**
*
*@brief  The replace function, 
*
*@param  first param
*
*@param  second param
*  
*/

bool operator!=(const PixelList& lhs, const PixelList& rhs)
{
   if(lhs.size_!=rhs.size_)
   {
	return false;
   }
   for(int i=0; i<rhs.size_; i++)
   {
	if(lhs.list_[i]!=rhs.list_[i])
	{
	   return true;
	}
   }
   return false;
}

/**
*
*@brief  The replace function, 
*
*@param  first param
*
*@param  second param
*  
*/

ostream& operator<<(ostream& out, const PixelList& rhs)
{
   for(int i=0; i<rhs.size_; i++)
   {
   out<<"{"<<rhs.list_[i]<<"}";
   }
   return out;
}

/**
*
*@brief  The replace function, 
*
*@param  first param
*
*@param  second param
*  
*/

const PixelList& PixelList:: operator=(const PixelList& rhs)
{
   if(this!= &rhs)
   {
	if(list_)delete[]list_;
	size_=rhs.size_;
	if(rhs.list_==0)
	{   
	   list_=0;
	}
	else
	{
	   list_=new(nothrow)Pixel[size_];
	   for(int i=0; i<rhs.size_; i++)
	   {
	      list_[i]=rhs.list_[i];
	   }
	}
   
   } 
   return *this;
}



