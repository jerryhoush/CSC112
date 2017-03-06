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
void multiplex(short samples[], int& numSamples);
void compress(short samples[], int& numSamples);
void stretch(short samples[], int& numSamples);
void clearScreen();
