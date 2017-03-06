#include <fstream>
#include <iostream>
#include "database.h"
using namespace std;

int main(int argc, char* argv[])
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

cout<<"Database has "<<n<<" ID numbers"<<" and requires "<<sizeof(int)*n<<" bytes"<<'\n';
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

   printValues(n, list, argv[3]);

   cout<<"Updated Database:"<<'\n';
   cout<<"Database has "<<n<<" ID numbers"<<" and requires "<<sizeof(int)*n<<" bytes"<<'\n';



}
