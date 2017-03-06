/**
* @file    lab6.cpp
* @author  Jerry Housh (housga12)
* @date    03/06/2014
* @version 1.0 
*
* @brief   This lab takes a jpeg image chosen by the user, shrinks the image from a maximum of 1000*1000 2-D array into a 100*100 2-D *	   array.  This array is then converted from integer values into characters ({'#', 'o', ':', '.', ' '}) which are then placed *	   into an ascii array (100*100). The newly converted array is then sent to a file and is printed out for the user to view.
*
* @section CSC 112. Dr. Fulp
*
*/

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
	   convertImage(image, nRow, nCol, ascii); 
	   writeImage(textFileName, ascii, nRow, nCol); 
   }
	else
	{
	   cout<<"Error, problem reading file \n";
	   return 1;
	}
	   return 0;
}
