#include <fstream>
#include <iostream>
#include <database.h>
using namespace std;

int search(int value, int list[], int n);
void addValue(int value, int*& list, int& n);
void deleteValue(int loc, int*& list, int& n);
void printValues(int& n, int list[]);

int main()
{
   int value=0;
   int n=0;
   int* list=0;
   int loc=0;
   char action;
   

   fstream inFile(argv[1], ios::in);

   while(inFile>>value)
   {
	if(search(value, list, n)==-1)
	{
	   addValue(value, list, n);
	}
   }
   inFile.close();

cout<<"Database has "<<n<<" ID numbers"<<"and requires "<<sizeof(int)*n<<" bytes"<<'\n';
cout<<"-------------------------------------------------"<<'\n';

   fstream upFile(argv[2], ios::in);
   while(upFile>>action>>value)
   {
	if(action=='a' || action=='A')
	{
	   if(search(value, list, n)==-1)
	   {
		addValue(value, list, n);
	   }
	}
	else if(action=='d' || action=='D')
	{
	   loc=search(value, list, n);
	   if(loc != -1)
	   {
		deleteValue(loc, list, n);
	   }
	}
   }

   printValues(n, list);

   cout<<"Updated Database:"<<'\n';
   cout<<"Database has "<<n<<" ID numbers"<<"and requires "<<sizeof(int)*n<<" bytes"<<'\n';



}

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
*@brief  The addValue function runs through the database of ID's, storing the values in ascending order, one by one into the array
*  
*/

void addValue(int value, int*& list, int& n)
{
   int* tempList=new(nothrow)int[n+1];
   int i;
	for(i=0; i<n && list[i]<value; i++)
	{
	   tempList[i]=list[i];
	   tempList[i]=value;
	}
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
*/

void deleteValue(int loc, int*& list, int& n)
{
   if(n==0)
   {
	return;
   else if(n==1)
   {
	if(list)delete[]list;
	list=0;
	n=0;
   }
   else 
   {
	int* tempList=new(nothrow)int[n-1];
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
*@brief  This function reads through each value of the newly *	 constructed array of ID's and prints them out line *	 by line, producing the final.dat array of ID's
*  
*/

void printValues(int&n, int list[])
{
   fstream outFile(argv[3], ios::out);
   for(int i=0; i<n; i++)
   {
	outFile<<list[i]<<'\n';
   }
	outFile.close();
}
