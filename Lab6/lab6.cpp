#include <iostream>
#include <fstream>
#include "jpeg.h"
using namespace std;

void shrinkImage(unsigned char image[][MAX_COL], int&nRow, int&nCol);
void convertImage(unsigned char image[][MAX_COL], int&nRow, int&nCol, char ascii[][100]);
void writeImage(string textFileName, char ascii[][100], int& nRow, int& nCol);

//char* argv[] is a pointer to a character (it is an array of pointers) so in this case to multiple characters
//argv[0]=./a.out
//argv[1]=best.jpg
int main(int argc, char* argv[])
{
   if(argc < 3)
   {
	cout << "Error, must specify JPEG and text file names \n";
	return 1;
   }
   string jpegFileName = argv[1]; ///> JPEG filename
   string textFileName = argv[2]; ///> text filename
   unsigned char image[MAX_ROW][MAX_COL]; ///> the pixel image
   int nRow = 0; ///> number of rows in image
   int nCol = 0; ///> number of columns in image
   char ascii[100][100]; ///> the ASCII image

   if(readJPEGfile(jpegFileName, image, nRow, nCol))
   {
	cout<<"image size is "<<nRow<<'x'<<nCol<<" pixels \n";
	if(nRow > 100 || nCol > 100)
	{
	   shrinkImage(image, nRow, nCol); 
	   cout<<"image reduced to "<<nRow<<'x'<<nCol<<" pixels \n"
;
	}
	   convertImage(image, nRow, nCol, ascii); // you write this function
	   writeImage(textFileName, ascii, nRow, nCol); // you write this function
   }
	else
	{
	   cout<<"Error, problem reading file \n";
	   return 1;
	}
	   return 0;
   }

void shrinkImage(unsigned char image[][MAX_COL], int&nRow, int&nCol)
{
   unsigned char temp[100][100];
   int nR=nRow/100; //how many groups of 100 (rows)
   int nC=nCol/100; //how many groups of 100 (columns)
   int r=0; //counter in temp matrix for rows
   int c=0; //counter in temp matrix for columns
   int n=0; //number of elements 
   int sum=0;

   for(int i=0; i<nRow; i+=nR)
   {
      c=0;
      for(int j=0; j<nCol; j+=nC)
      {
         sum=0;
	 n=0;
	 for(int k=i; k<i+nR && k<MAX_ROW; k++)
	 {
	    for(int l=j; l<j+nC && l<MAX_COL; l++)
	    {
	       sum+=image[k][l];
	       n++;
	    }
	 }
         temp[r][c]=sum/n;
         c++;
      }
         r++;
   }
	 nRow=r;
	 nCol=c;
for(int i=0; i<nRow; i++)  
   {
      for(int j=0; j<nCol; j++)
      { 
	 image[i][j]=temp[i][j];
      }
   }
}


/*
//Want to replace each number in the 2-D array with a character {'#', 'o', ':', '.', ' '} into the ascii array. Need to figure out the range of the array (highest-lowest). After that, cut that number (the range) into 5 equal pieces and assign each of these pieces to their according characters.
//Need 2 nested for loops (4 for loops total)
//The first nested loop determines the range
//The second nested loop goes through the array and, based on the range, converts the numbers from image into characters to ascii
*/
void convertImage(unsigned char image[][MAX_COL], int&nRow, int&nCol, char ascii[][100])
{
   int range=0;  
   int rangeSec=0;
   int hi=image[0][0];
   int lo=image[0][0];

   
   for(int i=0; i<nRow; i++) //converts nums to chars? 
   {
      for(int j=0; j<nCol; j++)
      { 
	 if(hi<image[i][j])
	     hi=image[i][j];
	 else if(lo>image[i][j])
	     lo=image[i][j];
      }
   }
	range=(hi-lo);
	rangeSec=range/5;


   for(int i=0; i<nRow; i++)
   {
      for(int j=0; j<nCol; j++) 
      {
	  if(image[i][j]<=(lo+rangeSec))
	     ascii[i][j]='#';
	  else if(image[i][j]<=(lo+(rangeSec*2)))
	     ascii[i][j]='o';
	  else if(image[i][j]<=(lo+(rangeSec*3)))
	     ascii[i][j]=':';
	  else if(image[i][j]<=(lo+(rangeSec*4)))
	     ascii[i][j]='.';
	  else //if(image[i][j]<=(lo+(rangeSec*5)))
	     ascii[i][j]=' ';
      }
   }
}

void writeImage(string textFileName, char ascii[][100], int& nRow, int& nCol)
{
fstream dataFile(textFileName.c_str(), ios::out);
for(int i=0; i<nRow; i++)
   {
      for(int j=0; j<nCol; j++) 
      {
	  dataFile<<ascii[i][j];
      }
	  dataFile<<'\n';
   }
dataFile.close();
}







