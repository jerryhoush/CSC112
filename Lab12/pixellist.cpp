#include "pixellist.h"
#include <iostream>
#include "pixel.h"


using namespace std;

/**
*
*@brief  The null constructor, generates an empty PixelList
*
*@param  list_ stores the length of the list (0)
*
*@param  size_ stores the size of the list (0)
*  
*/

PixelList:: PixelList()
{
   list_=0;
   size_=0;
}

/**
*
*@brief  The copy constructor, makes a deep copy of a 
	 PixelList by creating a for loop that stores 
	 the copied list's values into a new list  
*
*@param  
*
*@param  second param
*  
*/

PixelList:: PixelList(const PixelList& list);
{
   list_=new(nothrow)Pixel[list.size_];
   for(int i=0; i<list_; i++;)
   {
	list_[i]=list.list_[i];
   }
   size_=list_.size_;
}

/**
*
*@brief  The Pixel constructor, which creates a PixelList from a Pixel (used from lab 10). The list_ stores the values of Pixel in an array. size_ is set to one
*
*@param  first param
*
*@param  second param
*  
*/

PixelList:: PixelList(Pixel p)
{
   list_=new(nothrow) Pixel[1];
   list_[0]=1;
   size_=1;
}

/**
*
*@brief  The destructor, which deletes a PixelList when called upon
*
*@param  first param
*
*@param  second param
*  
*/

PixelList:: ~PixelList(Pixel p);
{
   if(list_)delete[]list_;
 
}

/**
*
*@brief  The append function adds yet another Pixel list to list_
*
*@param  first param
*
*@param  second param
*  
*/

void append(Pixel pixel)
{
   Pixel* temp=new(nothrow) Pixel[size_+1];
   int i=0;
   for(i=0; i<size_; i++)
   {
	temp[i]=list_[i];
   }
   size_++;
   temp[i]=pixel;
   if(list_)delete[]list_;
   list_=temp;
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

void replace(Pixel oldPixel, Pixel newPixel)
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
}

PixelList:: operator==(const PixelList& lhs, const PixelList& rhs)
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

PixelList:: operator!=(const PixelList& lhs, const PixelList& rhs)
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

ostream& operator<<(ostream& out, const PixelList& rhs)
{
   for(int i=0; i<rhs.size_; i++)
   {
   out<<"{"<<rhs.list_[i]<<"}";
   return out;
}

const PixelList& PixelList::operator=(const PixelList& rhs)
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
	      list_[i]=rhs.list[i];
	   }
	}
   }
   return *this;
}

}
