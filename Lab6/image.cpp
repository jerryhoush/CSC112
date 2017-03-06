/**
*
*@brief  shrinkImage is used to shrink the original image (which can be up to 1000*1000 2-D array) into the ascii 2-D array, which is *	 100*100.  It does this by breaking up the 2-D array into sections, then averaging those sections to then place into a *	 temporary array. The temporary array is then stored back into the original image array.
*
*@param  temp[][] is the temporary array which stores the newly shrunken values
*@param  nR is the number of rows in the 100*100 array
*@param  nC is the number of columns in the 100*100 array
*@param  r is the counter for the temporary array (rows)
*@param  c is used as the counter for the temporary array (columns)
*@param  n is a counter used for the new number of elements in the temporary array
*@param  sum stores the average numbers recieved from the two for loops
*
*/

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
*
*@brief  convertImage replaces each number in the new 2-D array with a character ({'#', 'o', ':', '.', ' '}) into the ascii array. *	 The range of the new array is calculated by taking the highest value subtracted by the lowest value. It is then divided into *	 5 equal parts, and those parts provide answers to which character gets assigned to which number in the array. The function *	 contains two nested loops: the first determines the range and the second goes through and converts the number from the image *	 into characters for the ascii array.
*
*@param  range is used to store the range of values in the array
*@param  rangeSec stores the value of the range divided by 5
*@param  hi stores the highest value of the array
*@param  lo stores the lowest value of the array
*
*/

void convertImage(unsigned char image[][MAX_COL], int&nRow, int&nCol, char ascii[][100])
{
   int range=0;  
   int rangeSec=0;
   int hi=image[0][0];
   int lo=image[0][0];

   
   for(int i=0; i<nRow; i++) 
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

/*
*
*@brief  writeImage is used to print out the ascii array so that it is visible to the user. It prints out to a file thanks to the *	 fstream function, the nested for loop fills the dataFile with the characters from the array
*
*@param  dataFile is used to print out the array to a file
*
*/

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
