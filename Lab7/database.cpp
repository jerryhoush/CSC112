#include <iostream>
#include <fstream>
#include "database.h"
using namespace std;

/**
*
*@brief  This function runs through the entire array of *	 information in order to determine the number of ID's *	 in the database
*
*@param  int value stores the value of the ID in a certain *        location of the list[] array
*
*@param  int list[] stores the values of the database
*
*@param  int n stores the location of the values in the list[] *        array
*  
*/

int search(int value, int list[], int n)
{
   for(int i=0; i<n; i++)
   {
	if(value==list[i])
	{
	   return i;
	}
   }
   return -1;
}

/**
*
*@brief  The addValue function runs through the database of *	 ID's, storing the values in ascending order, one by *	 one into the array
*
*@param  int value stores the value of the ID in a certain *        location of the list[] array
*
*@param  int list[] stores the values of the database
*
*@param  int n stores the location of the values in the list[] *        array
*  
*/

void addValue(int value, int list[], int& n)
{
   int loc=n;
   for(int i=n-1; i>=0; i--)
   {
   	if(list[i]>value)
	{
	    loc=i;
	}
   }
	//if((n<MAX_SIZE) && (loc>=n))
	{
	   for(int i=n; i>loc; i--)
	   {
	      list[i]=list[i-1];
	   }
	   list[loc]=value;
	   n++;
	}
}

/**
*
*@brief  The deleteValue function runs through the entire *	 array of ID's and determines whether or not certain *	 ID values need to be removed (by instruction from *	 the main)
*
*@param  int value stores the value of the ID in a certain *        location of the list[] array
*
*@param  int list[] stores the values of the database
*
*@param  int n stores the location of the values in the list[] *        array
*  
*/

void deleteValue(int loc, int list[], int& n)
{
   for(int i=loc; i<n; i++)
   {
	list[i]=list[i+1];
   }
	n--;
}

/**
*
*@brief  This function reads through each value of the newly *	 constructed array of ID's and prints them out line *	 by line, producing the final.dat array of ID's
*
*@param  int value stores the value of the ID in a certain *        location of the list[] array
*
*@param  int list[] stores the values of the database
*
*@param  int n stores the location of the values in the 
* 	 list[] array
*  
*/

void printValues(int&n, int list[])
{
   fstream outFile("final.dat", ios::out);
   for(int i=0; i<n; i++)
   {
	outFile<<list[i]<<'\n';
   }
	outFile.close();
}
