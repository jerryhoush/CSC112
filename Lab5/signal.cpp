/**
*
*@brief  Asks the user to input the data file that will be *        used to collect data from.
*
*@param  option takes input from the user in order to *        determine which function to perform 
*
*@param  loaded is a check that the input from the user is *        valid
*/

void displayMenu(int&option, bool& loaded)
{
    cout<<"Digital Signal Processing Program"<<'\n';
   cout<<"-----------------------------------------------"<<'\n';
   cout<<"1) Read audio data from file   5) Play audio"<<'\n';
   cout<<"2) Display signal              6) Multiplex"<<'\n';
   cout<<"3) Adjust volume               7) Compress"<<'\n';
   cout<<"4) Reverse audio               8) Stretch"<<'\n';
   cout<<"              0) Quit                           "<<'\n';
   cout<<"Enter option (0 - 8) -->"<<'\n';
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
	else if (option == 6)
		{loaded = true;}
	else if (option == 7)
		{loaded = true;}
	else if (option == 8)
		{loaded = true;}
	else
		{loaded = false;}
}

/**
*
*@brief  Asks the user for an audio file and stores the *        file into the samples array
*
*@param  fileName is the name of the audio file being *        stored 
*@param  maxSize is the maximum number of storage in the *        array
*@param  numSamples is the number of samples in the audio *        file
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
*@brief  This function asks the user for a starting and *        stopping point and displays the audio signal *        through "<" or ">" depending on if the signal is *        positive or negative
*
*@param  start stores the starting point that the user *        chooses
*@param  stop stores the stopping point that the user *        chooses
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
*@brief  adjustAudio allows the user to increase or *        decrease the sound of their audio file
*
*@param  sound is the starting point for volume, which can *        be adjusted
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
*@brief  This function asks the user for a second audio file to play over the first. The two arrays are added together, the shortest added to the longest.
*
*@param  fileName is used to ask the user for the second *        file
*@param  samples2 is the second array that the user inputs
*@param  numSamples2 is the number of samples from the *        second array
*
*/

void multiplex(short samples[], int& numSamples)
{
   string fileName;
   short samples2[MAX_SIZE];
   int numSamples2;
   
   cout << "Enter .au file name -> ";
   cin >> fileName;

   cout << "Reading the file: " << fileName << '\n';
   readAuFile(fileName, samples2, MAX_SIZE, numSamples2);
   cout << numSamples2 << " samples read, signal duration "<< numSamples2/8000.0 << " seconds \n";

   if(numSamples > numSamples2)
   {
        for(int j=0; j<numSamples2; j++)
	   {samples[j]+=samples2[j];}
   }
   else 
   {   
	for(int j=0; j<numSamples; j++)
	   {samples2[j]+=samples[j];}
	numSamples = numSamples2;	
	for(int j=0; j<numSamples; j++)
	   {samples[j]=samples2[j];}
   

}
}
/**
*
*@brief  This function takes the audio file and makes *        deletions to every other sample in the array, *        shortening it in half. 
*
*@param  int i is used as a placeholder array
*@param  int j is used as the first array
*
*/

void compress(short samples[], int& numSamples)
{
 
cout<<"Compress Audio"<<'\n';

   int i=0;
   int j=0;
     while(j<numSamples)
     {
	samples[i]=samples[j];
        i++;
	j+=2;
     }
        numSamples=i;
   cout<<"After compressing, audio has "<<numSamples<<"and duration of "<<numSamples/8000.0<<"seconds"<<'\n';

   myPause();
}

/**
*
*@brief  This function takes the audio file and doubles *        each of the samples in the array, causing the *        array size to double
*
*@param  temp[] is used as a placeholder array
*@param  int j is used to store the samples of the primary *        array
*@param  int i is used to store the samples of the *         secondary array
*
*/

void stretch(short samples[], int& numSamples)
{
  cout<<"Stretch audio"<<'\n';
   
  short temp[MAX_SIZE];
  int j,h;
  for(j=0, h=0; j<numSamples && h < MAX_SIZE; j++)
  {
      temp[h]=samples[j];
      h++;
       if(h<MAX_SIZE)
 	{
	   temp[h]=samples[j];
	   h++;
	}
  }
     numSamples=h;
     for(j=0; j<numSamples; j++)
		samples[j]=temp[j];

   cout<<"After stretching, audio has 29766 samples and duration of "<<numSamples/8000.0<<"seconds"<<'\n';
   myPause();

}

/*
*
*@brief  The myPause function is used to return to the *        mainscreen
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

