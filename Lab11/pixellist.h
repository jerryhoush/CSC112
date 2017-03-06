/**
* @file    lab11.cpp
* @author  Jerry Housh (housga12)
* @date    04/21/2014
* @version 1.0 
*
* @brief   This program contains a PixelList class that is used to generate 
*	   Pixel List objects. Objects in these list's can be appended,
*	   replaced, copied into other lists, and destroyed. 
*
* @section CSC 112. Dr. Fulp
*
*/

#ifndef PIXELLIST_H
#define PIXELLIST_H
#include "pixel.h"
#include <iostream>

using namespace std; 

class PixelList
{

   public:
	PixelList(); //null constructor
	PixelList(Pixel p); //pixel constructor
	PixelList(const PixelList& list);  //copy constructor
 	~PixelList(); //destroy constructor
	int size()const {return size_;} //member function size
	friend bool operator==(const PixelList& lhs, const PixelList& rhs); 
	friend bool operator!=(const PixelList& lhs, const PixelList& rhs); 
	friend PixelList operator+(const PixelList& lhs, const PixelList& rhs);
	friend ostream& operator<<(ostream& out, const PixelList& rhs);
	const PixelList& operator=(const PixelList& rhs);
	void append(Pixel pixel);
	void replace(Pixel oldPixel, Pixel newPixel);
	friend class PixelLinkList;

   private:
	Pixel* list_;
	int size_;

};

#endif
