 #include <fstream>
#include <iostream>
#include "database.h"
using namespace std;

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

