/** 
 *  @file driver.cpp
 *  @brief CSC 112, Lab 11, driver program  
 *
 *  This program tests the PixelList class, enjoy!
 *  
 *  @author 	Jerry Housh (housga12)
 *  @date	04/21/2014  
 *  @bug	No known bugs.
 */

#include <iostream>
#include "pixellist.h"
#include "pixel.h"
using namespace std;

int main()
{

Pixel p1(30,70,95);
Pixel p2(10,20,30);
PixelList list1(p2);
PixelList list2;
PixelList list3(Pixel(35,35,35));
PixelList list4(list3);
PixelList list5(p1);



cout<<" "<<'\n';

cout<<"list1: "<<list1<<'\n';
cout<<"list2 (Null): {[ "<<list2<<"]}"<<'\n';
cout<<"list3: "<<list3<<'\n';
cout<<"list4: "<<list4<<'\n';
cout<<"list5: "<<list5<<'\n';
cout<<" "<<'\n';

cout<<"===========Null, Copy,and Pixel Constructor Tests============"<<'\n';
cout<<" "<<'\n';
cout<<"Null Constructor: {["<<list2<<"]}"<<'\n';
cout<<"Copy Constructor (copy of list3 into list4): "<<list4<<'\n';
cout<<"Pixel Constructor:"<<list3<<'\n';
cout<<" "<<'\n';

cout<<"===============Size, Append, and Replace Tests==============="<<'\n';
cout<<" "<<'\n';
list5.append(Pixel(10,10,10));
cout<<"Append Test (adds list1 to list5): "<<list5<<'\n';
cout<<"Size Test (list5): "<<list5.size()<<" items in the list."<<'\n';
list5.replace(Pixel(10,10,10), Pixel(40,40,40));
cout<<"Replace Test (replaces Pixel(10,10,10) with Pixel(40,40,40): "<<list5<<'\n';
cout<<" "<<'\n';

}

