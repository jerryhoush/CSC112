#include "pixel.h"
#include <cassert>
#include "pixelnode.h"
#include "pixellinklist.h"
#include <iostream>
using namespace std;

/**
*
*@brief  The Null Constructor. Sets the linked list to 0
*
*@param  head_ is set to 0 
*  
*/

PixelLinkList::PixelLinkList() {head_=0;} //Null Constructor

/**
*
*@brief  The Pixel Constructor. Generates a new pixel node 
*
*@param  head_'s next value will be set to 0  
*
*@param  value_ is set to the value of p
*  
*/

PixelLinkList::PixelLinkList(const Pixel& p) //Pixel Constructor
{
   head_=new(nothrow)PixelNode;
   assert(head_!=0);
   head_->value_=p;
   head_->next_=0;
}

/**
*
*@brief  The Copy Constructor. Checks to make sure head_ is at 0. If not, head_ is set to 0 and the value of the next spot (value_) is set to value_. Source list and destruction list are used to figure out what is pointing to the next node  
*
*@param  slist is used as the source list (what is copied)
*
*@param  dlist is used as the destination list (where the copied list will be stored) 
*  
*/

PixelLinkList::PixelLinkList(const PixelLinkList& list) //Copy Constructor
{
   if(list.head_==0)
   {
	head_=0;
   }
   else
   {
	head_=new(nothrow)PixelNode;
	assert(head_!=0);
	head_->value_=list.head_->value_;
	head_->next_=0;
	PixelNode* slist=list.head_; //source list
	PixelNode* dlist=head_; //destination list
	slist=slist->next_; //points to next node in the list
	while(slist!=0)
	{
	   dlist->next_=new(nothrow)PixelNode;
	   assert(dlist->next_!=0);
	   dlist=dlist->next_;
	   dlist->value_=slist->value_;
	   slist=slist->next_;
	}
   dlist->next_=0;
   }
}

/**
*
*@brief  The "<<" operator overload function. Overloads the "<<" operator and points to an empty list if the cursor is equal to 0 *	 and points to a value for the rest of the linked list
*  
*/

ostream& operator<<(ostream& out, const PixelLinkList& rhs) //Output Operator
{
   PixelNode* cursor=rhs.head_;
   if(cursor==0)
   {
	out<<"empty list"<<'\n';
   }
   else
   {
	while(cursor!=0)
	{
	   out<<cursor->value_<<", ("<<cursor->next_<<")";
	   cursor=cursor->next_;
	}
   }
   return out;
}

/**
*
*@brief  The append function. Adds a new pixel node to the end of the list
*
*@param  head_ is set to the beginning of the list
* 
*@param  cursor moves through the list of nodes and sets values
*  
*/

void PixelLinkList:: append(const Pixel& pix) //Append Function
{
   if(head_==0)
   {
	head_=new(nothrow)PixelNode;
	head_->value_=pix; //sets value brought in
	head_->next_=0; //sets to null
   }
   else
   {
	PixelNode* cursor=head_; //starts at the beginning 
	while(cursor->next_!=0)
	{
	   cursor=cursor->next_;
	}
	cursor->next_=new(nothrow)PixelNode;
	assert(cursor->next_!=0);
	cursor=cursor->next_; //moves over to the new node
	cursor->value_=pix;
	cursor->next_=0; //last guy parked at 0;
   }
}

/**
*
*@brief  The destructor. Points the node to 0 and breaks the link
*
*@param  prev is pointed to 0
*
*@param  cursor is pointed to next_, which is assigned 0
*  
*/

PixelLinkList::~PixelLinkList()  //Destructor
{
   PixelNode* prev=head_;
   PixelNode* cursor=head_;
   while(cursor!=0) //as long as cursor points to something
   {
	cursor=cursor->next_;
	prev->next_=0; //breaks the link, ready to reassign
	prev=cursor;
   }
}

/**
*
*@brief  The remove function, which removes the last node in the list
*  
*/

bool PixelLinkList:: remove(const Pixel& pix)  //Remove Function
{
   if(head_==0)return false;
   PixelNode* current=head_;
   PixelNode* prev;
   if(head_->value_==pix)
   {
	head_=head_->next_;
	current->next_=0;
	delete current;
   }
   else
   {
	while(current!=0)
	{
	   if(current->value_==pix)
	   {
		prev->next_=current->next_;
		current->next_=0;
		delete current;
		return true;
	   }
	   prev=current;
	   current=current->next_;
	}
   }
   return false;
}

/**
*
*@brief  The operator= overload, which allows comparisions between lists to be made
*
*@param  head_ is the lhs argument
*
*@param  temp.head_ is the rhs argument
*  
*/

const PixelLinkList& PixelLinkList:: operator=(const PixelLinkList& rhs)  //= Operator
{
   if(this!=&rhs)
   {
	PixelLinkList temp(rhs);
	head_=temp.head_;
	temp.head_=0;
   }
   return *this;
}

/**
*
*@brief  The operator+ overload. Allows nodes to be added to a list
*
*@param  result is the result of the added value to the list 
*  
*/

PixelLinkList operator+(const PixelLinkList& lhs, const PixelLinkList& rhs) //+ Operator
{
   PixelLinkList result;
   PixelNode* c = lhs.head_;
   while(c!=0)
   {
	result.append(c->value_);
	c=c->next_;
   }
   c=rhs.head_;
   while(c!=0)
   {
	result.append(c->value_);
	c=c->next_;
   }
   return result;
}

/**
*
*@brief  The PixelList Constructor. Converts a pixellist to a pixellinklist
*  
*/

PixelLinkList:: PixelLinkList(const PixelList& pList) //PixelList Constructor
{
   if(pList.size()==0)
   {
	head_=0;
   }
   else
   {
	head_=0;
	for(int i=0; i<pList.size(); i++)
	{
	   append(pList.list_[i]);
	}
   }
}

/**
*
*@brief  The size() function. Counts the number of nodes in the linked list
*
*@param  n is used as the counter
*  
*/

int PixelLinkList:: size()const  //Size() Function
{
   int n=0; //counter
   PixelNode* cursor=head_; //points to first node in the list
   while(cursor!=0)
   {
	n++; //counter
	cursor=cursor->next_;
   }
   return n;
}

