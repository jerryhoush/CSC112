/**
* @file    lab12.cpp
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

#ifndef PIXELINKLIST_H
#define PIXELINKLIST_H
#include <iostream>
#include "pixelnode.h"
#include "pixel.h"
#include "pixellist.h"
using namespace std;

class PixelLinkList
{
   public:
	PixelLinkList(); //null constructor
	PixelLinkList(const Pixel& p); //creates new pixel
	PixelLinkList(const PixelLinkList& pList); //new link list
	~PixelLinkList(); //destructor 
	void append(const Pixel& pix);  //append pix as the last node 
	bool remove(const Pixel& pix);  //remove all occurences of pix
	friend ostream& operator<<(ostream& out, const PixelLinkList& rhs);
	friend PixelLinkList operator+(const PixelLinkList& lhs, const PixelLinkList& rhs);
	const PixelLinkList& operator=(const PixelLinkList& rhs);
	PixelLinkList(const PixelList& pList); //converts a PixelList to a LinkList
	int size()const;

		
   private:
	PixelNode* head_;
};

#endif
