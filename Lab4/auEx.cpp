/** 
 *  @file    auEx.cpp
 *  @brief   CSC 112, Lab 4, An example audio program  
 *  @author  Pluf (?)
 *  @date    2/8/2014  
 *  @version 2.0
 *
 *  Tests if the sound libraries are installed correctly
 *
 *   Program requires sound.h, sound.o, -lasound  
 *   Compile command  
 *      g++ auEx.cpp sound.o -lasound  
 *
 */

#include <iostream>
#include "sound.h"

using namespace std;  

#define MAX_SIZE 240000

int main()
{
   string fileName;           ///< name of the au file
   short  samples[MAX_SIZE];  ///< array of samples
   int    numSamples;         ///< number of samples

   cout << "Enter .au file name -> ";
   cin >> fileName;

   cout << "Reading the file: " << fileName << '\n';
   readAuFile(fileName, samples, MAX_SIZE, numSamples);
   cout << numSamples << " samples read, signal duration "
        << numSamples/8000.0 << " seconds \n";

   playPCMsamples(samples, numSamples);

   return 0;  
}


