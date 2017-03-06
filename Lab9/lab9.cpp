#include <fstream>
#include <iostream>
#include <database.h>
using namespace std;

int search(int value, int list[], int n);
void addValue(int value, int*& list, int& n, int& max);
void deleteValue(int loc, int*& list, int& n, int& max);
void printValues(int& n, int list[]);


int main()
{
   int value=0;
   int n=0;
   int* list=new(nothrow)int[20];
   int loc=0;
   int max=20;
   char action;

   if(argc<4)
   {
	cout<<"Error: Not enough arguments."<<'\n';
   }
   

   fstream inFile(argv[1], ios::in);

   while(inFile>>value)
   {
	if(search(value, list, n)==-1)
	{
	   addValue(value, list, n, max);
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
		addValue(value, list, n, max);
	   }
	}
	else if(action=='d' || action=='D')
	{
	   loc=search(value, list, n);
	   if(loc != -1)
	   {
		deleteValue(loc, list, n, max);
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

   int i;
   for(i=n-1; i>0&&value&<list[i]; i--)
	list[i+1]=list[i];
   list[i+1]=value;
   n++;
//lab 7 insert:

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
*@brief  The deleteValue function runs through the entire array of ID's and determines whether or not certain ID values need to be removed (by instruction from the main)
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

void printValues(int&n, int list[])
{
   fstream outFile(argv[3], ios::out);
   for(int i=0; i<n; i++)
   {
	outFile<<list[i]<<'\n';
   }
	outFile.close();
}




