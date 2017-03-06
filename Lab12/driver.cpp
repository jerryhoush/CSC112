/** 
 *  @file driver.cpp
 *  @brief CSC 112, Lab 12, driver program  
 *
 *  This program tests the PixelLinkList class. Enjoy! 
 *  
 *  @author 	Jerry Housh (housga12)
 *  @date	04/28/2014  
 *  @bug	No known bugs.
 */

#include <iostream>
#include "pixellinklist.h"
#include "pixellist.h"
#include "pixel.h"
using namespace std;

int main()
{

   cout<<"Null Constructor Test:"<<'\n';
   PixelLinkList list1;
   cout<<list1<<'\n';
   cout<<" "<<'\n';
   cout<<"Pixel Constructor Test:"<<'\n';
   PixelLinkList list2(Pixel(10,10,10));
   cout<<list2<<'\n'<<flush;
   cout<<" "<<'\n';
   cout<<"PixelList Constructor Test:"<<'\n';
   PixelList pList(Pixel(20,20,20));
   PixelLinkList list3(pList);
   cout<<list3<<'\n'<<flush;
   cout<<" "<<'\n';
   cout<<"Copy Constructor Test:"<<'\n';
   PixelLinkList list4(list3); 
   cout<<list4<<'\n'<<flush;
   cout<<" "<<'\n';
   cout<<"Append Test:"<<'\n';
   list4.append(Pixel(30,30,30));  //append
   cout<<list4<<'\n'<<flush;
   cout<<"Size Test:"<<'\n';
   cout<<list4.size()<<'\n'<<flush; //size
   cout<<" "<<'\n';
   cout<<"Equals Operator Test:"<<'\n';
   PixelLinkList list5=list4; //equals operator
   cout<<list5<<'\n'<<flush;
   cout<<" "<<'\n';
   cout<<"Replace Test:"<<'\n';
   list4.remove(Pixel(20,20,20)); //remove
   cout<<list4<<'\n'<<flush;
   cout<<" "<<'\n';
   cout<<"+ Operator Overload Test:"<<'\n';
   cout<<list2+list3<<'\n'<<flush;
   cout<<Pixel(30,30,30)+list3<<'\n'<<flush; //+ overload
   cout<<" "<<'\n';
   cout<<"PixelList + PixelLinkList Test:"<<'\n';
   cout<<pList+list3<<'\n'<<flush; //pixellist + linklist
   cout<<" "<<'\n';
return 0;

}
