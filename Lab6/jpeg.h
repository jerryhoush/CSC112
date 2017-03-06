#ifndef JPEG_H  
#define JPEG_H  

/** 
 *   @file jpeg.h
 *   @author Pluf (?) 
 *   @date 2/28/2014 
 *   @version 1.0 
 *    
 *   @brief CSC 112, Lab 6, header file for JPEG image library  
 *  
 *   Requires libjpeg and imagemagick libraries, must be compiles with  
 *   the jpeg.o, -lg, and -ljpeg libraries, for example if your program  
 *   is called main.cpp  
 *  
 *     g++ main.cpp jpeg.o -lg -ljpeg  
 *
 *   Function Descriptions:
 *    Functions will read JPEG images and store into 2-dimensional array
 * 
 */


#include <iostream>  
#include <stdio.h>
#include <string.h>  
#include <jpeglib.h>
#include <stdlib.h>

using namespace std;  

#define MAX_ROW 1000  
#define MAX_COL 1000  

/**
 * @brief   reads a JPEG file and saves the pixels in the image array
 * 
 * @param   fileName is the name of the JPEG file  
 * @param   image will contain the pixel values of the array  
 * @param   nRow is the number of rows in the image  
 * @param   nCol is the number of columns in the image  
 * 
 * @returns true if successful, false otherwise
 *
 */
bool readJPEGfile(string fileName, unsigned char image[][MAX_COL], int &nRow, int& nCol);  

/**
 * @brief   writes the raw image data stored in the raw_image buffer to a JPEG
 *          image with default compression and smoothing options in the file
 *          specified by filename.
 *
 * @param   fileName is the name of the JPEG file  
 * @param   image is an array of pixel values  
 * @param   nRow is the number of rows in the image  
 * @param   nCol is the number of columns in the image  
 * 
 * @returns true if successful, false otherwise
 */
bool writeJPEGfile(string fileName, unsigned char image[][MAX_COL], int &nRow, int& nCol);  

#endif  


