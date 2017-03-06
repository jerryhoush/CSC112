/**
* @file    lab4.cpp
* @author  Jerry Housh (housga12)
* @date    02/21/2014
* @version 1.0 
*
* @brief   CSC 112, Lab 4. This lab uses audio files and gives the user multiple       *          control options, such as playing the audio file, reversing the audio, and *          increasing/decreasing the volume
*
* @section CSC 112. Dr. Fulp
*
*/

#include <iostream>
#include "sound.h"
#include <stdio.h>
#define MAX_SIZE 240000
using namespace std;

void displayMenu(int& option, bool& loaded);
void readFile(string fileName, short samples[], int maxSize, int& numSamples);
void displaySignal(int numSamples, short samples[]);
void adjustAudio(short samples[], int numSamples);
void reverseAudio(short samples[], int numSamples);
void playAudioSignal(string fileName, int numSamples, short samples[]);
int myPause();
void clearScreen();

int main()
{
	int numSamples;
	short samples[MAX_SIZE];
	string fileName;
	int maxSize=0;
	int option;
	bool loaded = false;

	displayMenu(option, loaded);

	while(option != 0)
	{
	if(option == 1)
		{readFile(fileName, samples, maxSize, numSamples);}
	else if(option == 2 && loaded)
		{displaySignal(numSamples, samples);}
	else if(option == 3 && loaded)
		{adjustAudio(samples, numSamples);}
	else if(option == 4 && loaded)
		{reverseAudio(samples, numSamples);}
	else if(option == 5 && loaded)
		{playAudioSignal(fileName, numSamples, samples);}
		clearScreen();
		displayMenu(option, loaded);
	}
}

/**
*
*@brief  Asks the user to input the data file that will be used to collect data from.
*
*@param  option takes input from the user in order to determine which function to *        perform 
*
*@param  loaded is a check that the input from the user is valid
*/

void displayMenu(int&option, bool& loaded)
{
   cout<<"Digital Signal Processing Program"<<'\n';
   cout<<"-----------------------------------------------"<<'\n';
   cout<<"1) Read audio data from file   4) Reverse audio"<<'\n';
   cout<<"2) Display signal              5) Play audio"<<'\n';
   cout<<"3) Adjust volume               0) Quit"<<'\n';
   cout<<"                                            "<<'\n';
   cout<<"Enter option (0 - 5) -->"<<'\n';
   cin>>option;

	if (option == 1)
		{ loaded = true;}
	else if (option == 2)
		{ loaded = true;}
	else if (option == 3)
		{ loaded = true;}
	else if (option == 4)
		{ loaded = true;}
	else if (option == 5)
		{loaded = true;}
	else
		{loaded = false;}
}

/**
*
*@brief  Asks the user for an audio file and stores the file into the samples array
*
*@param  fileName is the name of the audio file being stored 
*@param  maxSize is the maximum number of storage in the array
*@param  numSamples is the number of samples in the audio file
*/

void readFile(string fileName, short samples[], int maxSize, int& numSamples)
{
   cout << "Enter .au file name -> ";
   cin >> fileName;

   cout << "Reading the file: " << fileName << '\n';
   readAuFile(fileName, samples, MAX_SIZE, numSamples);
   cout << numSamples << " samples read, signal duration "<< numSamples/8000.0 << " seconds \n";

myPause();
}

/**
*
*@brief  This function asks the user for a starting and stopping point and displays *        the audio signal through "<" or ">" depending on if the signal is positive or *        negative
*
*@param  start stores the starting point that the user chooses
*@param  stop stores the stopping point that the user chooses
*
*/

void displaySignal(int numSamples,short samples[])
{
	int start;
	int stop;

   cout<<"Signal Display\n";
   cout<<"Enter the start and stop index for the segment: "<<'\n';
   cout<<"Values range from 1 to "<<numSamples<<'\n';
   cout<<"Enter the start index --> \n";
   cin>>start;
   cout<<"Enter the stop index --> \n";
   cin>>stop;

	for(int j=start-1; j<stop; j++){
		cout<<j<<" ("<<samples[j]<<"): ";
		if(samples[j]>0){
			for(int h=0; h<(samples[j]/100); h++){
			cout<<">";
				}
		}	
		else
			for(int h=0; h<(samples[j]/-100); h++)
			cout<<"<";
	cout<<'\n';
    		}
  

}

/**
*
*@brief  adjustAudio allows the user to increase or decrease the sound of their audio *        file
*
*@param  sound is the starting point for volume, which can be adjusted
*
*/

void adjustAudio(short samples[], int numSamples)
{
  float sound = 1.0;
  cout<<"Enter a value in order to increase or decrease sound.  Enter a number larger than 1.0 in order to increase sound. Enter a number smaller than 1.0 in order to decrease sound. "<<'\n';
  cin>> sound;
  	while(sound<0 || sound>10){
		cout<<"not valid value. Enter a new value: "<<'\n';
		cin>>sound;
	}
  	for(int j=0; j<numSamples; j++){
		samples[j]=sound*samples[j];
	}
  	if(sound<1){
		cout<<"Volume has been decreased by "<<sound<<'\n';
	}
  	else{
		cout<<"Volume has been increased by "<<sound<<'\n';
        }
myPause();
}

/**
*
*@brief  reverseAudio switches the values of the array in order to reverse the sound *        of the audio file
*
*@param  temporary stores the values of samples array in order to perform the switch
*
*/

void reverseAudio(short samples[], int numSamples)
{
   cout<<"You have successfully reversed the audio."<<'\n';
   cout<<"  "<<'\n';
	short temporary;

	for(int j=0; j<numSamples/2; j++){
		temporary=samples[j];
		samples[j]=samples[numSamples-j-1];
		samples[numSamples-j-1]=temporary;
	}
myPause();
}

/**
*
*@brief  Displays the audio file being read, and plays the according file. Displays *        information about the file to the user.
*
*@param  The variable fileName is used to display what is being played to the user
*  
*/

void playAudioSignal(string fileName, int numSamples, short samples[])
{
   cout << "Reading the file: " << fileName << '\n';
   cout << numSamples << " samples read, signal duration "<< numSamples/8000.0 << " seconds \n";

   playPCMsamples(samples, numSamples);
   myPause();
}

/**
*
*@brief  This function returns the user to the main screen.
*
*
*
*/

int myPause()
{
   cout<<"Press <return> to continue."<<'\n';
   cout<<"  "<<'\n';
   getchar();
   getchar();
   return 0;
}
/**  
*   @brief  clears an Xterm window  
*   @return void  
*/  
void clearScreen()
{
   cout << char(27) << "[;H" << char(27) << "[2J" << '\n';
}







		
