#include "database.h"

/**
*
*@brief  This function runs through the entire array of information in order to determine the number of ID's in the database
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
*@brief  The addValue function runs through the database of ID's, storing the values in ascending order, 
*	 one by one into the array. If more space is needed, the physical size of the array can be increased
*  
*/

void addValue(int value, int*& list, int& n, int& max)
{
   
   if(n==max)
   {

	max+=int(max*0.1+0.5);
	int* tempList=new(nothrow)int[max];
	if(!tempList) exit(1);
	for(int i=0; i<n; i++)
	{
	   tempList[i]=list[i];
	}
	if(list)delete[]list;
	list=tempList;
   }
   int i;
   for(i=n-1; i>0 && value <list[i]; i--)
	list[i+1]=list[i];
   list[i+1]=value;
   n++;
}

/**
*
*@brief  The deleteValue function runs through the entire array of ID's and determines whether or not certain ID values need to be *	 removed (by instruction from the main) and can allocate more space if needed to the physical size of the array
*  
*/

void deleteValue(int loc, int*& list, int& n, int& max)
{



   if(max>20 && max>n*1.5)
   {
	max=int(n*1.2+0.5);
	int* tempList=new(nothrow)int[max];
	if(!tempList) exit(1);
	for(int i=0; i<n; i++)
	{
	   tempList[i]=list[i];
	}
	if(list)delete[]list;
	list=tempList;
   }
   //Lab7 insert:
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

