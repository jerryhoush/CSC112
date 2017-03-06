#include "database.h"

/**
*
*@brief  This function starts halfway through the array of IDs in order to determine if the value is 
*	 higher or lower than the midway value, and goes up or down from that spot depending on what the 
*	 mid-value is. 
*  
*@param  The variable hi is used to determine if the mid-value is higher 
*@param  The variable lo is used to determine if the mid-value is lower
*@param  The variable mid is used as a placeholder (starts in the middle of the array and moves up or down
*/

int search(int value, int list[], int n)
{
   int hi=n-1;
   int lo=0;
   int mid;
   while(hi>=lo)
   {
	mid=(hi+lo)/2;
	if(list[mid]==value)
	{
	   return mid;
	}
	else if(list[mid]<value)
	{
	   lo=mid+1;
	}
	else
	   hi=mid-1;
   }
   return -1;
	   
/*  for(int i=0; i<n; i++)
   {
	if(value==list[i])
	{
	   return i;
	}
   }
   return -1;
*/

}

/**
*
*@brief  The addValue function runs through the database of ID's, storing the values in ascending order, one by one into the array
*  
*@param  The tempList variable is a pointer to an array of values that is used to store the list into it
*/

void addValue(int value, int*& list, int& n)
{
   int* tempList=new (nothrow) int[n+1];
   int i;
	for(i=0; i<n && list[i]<value; i++)
	{
	   tempList[i]=list[i];
	}
	tempList[i]=value;
	for( ; i<n; i++)
	{
	   tempList[i+1]=list[i];
	}
	n++;
	if(list)delete[]list;
	list=tempList;
}

/**
*
*@brief  The deleteValue function runs through the entire array of ID's and determines whether or not certain ID values need to be removed (by instruction from the main)
*  
*@param  The tempList variable is a pointer to an array of values that is used to store the list into it
*
*/

void deleteValue(int loc, int*& list, int& n)
{
   if(n==0)
   {
	return;
   }
   else if(n==1)
   {
	if(list)delete[]list;
	list=0;
	n=0;
   }
   else 
   {
	int* tempList=new (nothrow) int[n-1];
	if(tempList==0)
	{
	   return;
	}
	int j=0;
	for(int i=0; i<n; i++)
	{
	   if(i!=loc)
	   {
		tempList[j]=list[i];
		j++;
	   }
	}
	n--;
	if(list)delete[]list;
	list=tempList;
	}
}

/**
*
*@brief  This function reads through each value of the newly constructed array of ID's 
*	 and prints them out line by line, producing the final.dat array of ID's
*  
*/

void printValues(int&n, int list[], char* fileName)
{
   fstream outFile(fileName, ios::out);
   for(int i=0; i<n; i++)
   {
	outFile<<list[i]<<'\n';
   }
	outFile.close();
}
