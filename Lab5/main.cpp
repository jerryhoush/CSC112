#include <iostream>
#include <stdio.h>
#include "sound.h"
using namespace std;

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
		
	else if(option == 6 && loaded)
		{multiplex(samples, numSamples);}
	else if(option == 7 && loaded)
		{compress(samples, numSamples);}
	else if(option == 8 && loaded)
		{stretch(samples, numSamples);}
clearScreen();
displayMenu(option, loaded);
	}

}
