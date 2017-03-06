#define MAX_SIZE 2000 
#include <fstream>
#include <iostream>
#include <database.h>
using namespace std;

int search(int value, int list[], int n);
void addValue(int value, int list[], int& n);
void deleteValue(int loc, int list[], int& n);
void printValues(int& n, int list[]);

int main()
{
   int value=0;
   int n=0;
   int list[MAX_SIZE];
   int loc=0;
   char action;

   fstream inFile("invent.dat", ios::in);

   while(inFile>>value)
   {
	if(search(value, list, n)==-1)
	{
	   addValue(value, list, n);
	}
   }
   inFile.close();

cout<<"Database has "<<n<<" ID numbers"<<'\n';
cout<<"-------------------------------------------------"<<'\n';

   fstream upFile("update.dat", ios::in);
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
   cout<<"Database has "<<n<<" ID numbers"<<'\n';
}

/**
*
*@brief  This function runs through the entire array of *	 information in order to determine the number of ID's *	 in the database
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


//testing: wget the files from webpage:
//to do this: wget www.cs.wfu.edu/~fulp/CSC112/iSmall.dat
//"					      "uSmall.dat
//"					      "fSmall.dat
//cp iSmall.dat invent.dat (overrights your invent.dat so dont do it until ready to test
//cp uSmall.dat update.dat


//then: go to program "diff": final.dat fSmall.dat
//If you hit return and get nothing back, congrats, they're the same
//If you hit return and get a lot of <, >, and ID #'s, that's not good, differing results. 


