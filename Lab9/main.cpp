#include <fstream>
#include <iostream>
#include "database.h"
using namespace std;

int main(int argc, char* argv[])
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
cout<<"Reading "<<argv[1]<<'\n';
cout<<"Database has "<<n<<" ID numbers. The array's physical size is "<<max<<" and requires "<<sizeof(int)*max<<" bytes"<<'\n';
cout<<"-----------------------------------------------------------------"<<'\n';

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

   printValues(n, list, argv[3]);
   cout<<"Reading "<<argv[2]<<'\n';
   cout<<"Updated Database:"<<'\n';
   cout<<"Database has "<<n<<" ID numbers. The array's physical size is "<<max<<" and requires "<<sizeof(int)*max<<" bytes"<<'\n';
   cout<<"--------------------------------------------------------------------"<<'\n';
   cout<<"Output written to "<<argv[3]<<'\n';

}
