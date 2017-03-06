
#ifndef AUFILE_H
#define AUFILE_H

/** 
 *   @file    sound.h
 *   @author  Pluf (?) 
 *   @date    2/8/2014 
 *   @version 2.0 
 *
 *   @brief CSC 112, header file for sound library  
 *
 *   Requires alsa sound libraries, must compile with  
 *   the audiolib.o and -lasound libraries, for example
 *   if your program is called program.cpp  
 * 
 *     g++ program.cpp audiolib.o -lasound  
 *
 *   Function Descriptions:
 *    Functions will read audio data from an .au file and
 *    play PCM samples using the speaker.
 * 
 */

#include<cstring>
using namespace std;  

/**  
 *   @brief  reads an au file and stores samples into an array
 *
 *   @param  fileName is the name of the au file  
 *   @param  sample is a short array, will contain audio samples
 *   @param  maxSize is the maximum size of the array  
 *   @param  numSamples is the number of samples in the array  
 *
 *   @return true if able to read file and save samples  
 */  
bool readAuFile(string fileName, short sample[], int maxSize,
                int& numSamples);


/**  
 *   @brief  plays audio samples (PCM) format stored in array  
 *
 *   @param  sample is an array (type short) of PCM samples
 *   @param  numSamples is the number of samples in the array  
 *
 *   @return void  
 */  
void playPCMsamples(short sample[], int numSamples);


#endif
