#include "pixellist.h"
#include "pixel.h"
#include <iostream>

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
*	 PixelList by creating a for loop that stores 
*	 the copied list's values into a new list  
*
*  
*/

PixelList:: PixelList(const PixelList& list)
{
   list_=new(nothrow)Pixel[list.size_];
   for(int i=0; i<list.size_; i++)
   {
	list_[i]=list.list_[i];
   }
   size_=list.size_;
}

/**
*
*@brief  The Pixel constructor, which creates a PixelList from a Pixel (used from lab 10). The list_ stores the values of Pixel in an array. size_ is set to one
*  
*/

PixelList:: PixelList(Pixel p)
{
   list_=new(nothrow) Pixel[1];
   list_[0]=p;
   size_=1;
}

/**
*
*@brief  The destructor, which deletes a PixelList when called upon
*  
*/

PixelList:: ~PixelList()
{
   if(list_)delete[]list_;
 
}

/**
*
*@brief  The append function. Adds yet another Pixel list to list_
*
*@param  temp is used to store values from the first list
*  
*/

void PixelList:: append(Pixel pixel)
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

