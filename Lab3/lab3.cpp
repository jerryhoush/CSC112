/**
* @file    Lab3.cpp
* @author  Jerry Housh (housga12)
* @date    02/07/2014
* @version 1.0 
*
* @brief   CSC 112, Lab 3, calls upon a data file in order to discover the highest daily return of the year, and the seasonal *		    daily returns for each of the four seasons. It then takes the data collected from the functions and displays *	 	    in the outputResults function
*
* @section CSC 112. Dr. Fulp
*
*/

#include <fstream>
#include <iostream>
using namespace std;

void inputFileName(string& fileName);
void recordHighestDailyReturn(double& DR, double& highestDR, int& day, int& month, int& year, int& highDay, int& highMonth, int& highYear);
void recordSeasonalDailyReturn(int& month, double& DR, double& summerSum, int& summerC, double& fallSum, int& fallC, double& winterSum, int& winterC, double& springSum, int& springC);
void outputResults(string& fileName, double& summerSum, int& summerC, double& fallSum, int& fallC, double& winterSum, int& winterC, double& springSum, int& springC, double& highestDR, int& highMonth, int& highDay, int& highYear);
double dailyReturn(double& price, double& oldPrice);

int main() 
{
	int year = 0;		//stores the value of a year
	int month = 0;		//stores the value of a month
	int day = 0;		//stores the value of a day
	double price = 0;	//stores the value of the price
	double oldPrice = 0;	//stores the value of the old price
	double highestDR = 0;	//stores the value of the highest daily return
	double DR = 0;		//stores the value of the daily return
	int highDay=0;		//stores the value of the day that has the highest daily return
	int highMonth=0;	//stores the value of the month that has the highest daily return
	int highYear=0;		//stores the value of the year that has the highest daily return
	int fallC=0;		//stores the value of the fall count 
	int winterC=0;		//stores the value of the winter count
	int springC=0;		//stores the value of the spring count
	int summerC=0;		//stores the value of the summer count
	double fallSum=0;	//stores the value of the fall sum
	double winterSum=0;	//stores the value of the winter sum
	double springSum=0;	//stores the value of the spring sum
	double summerSum=0;	//stores the value of the summer sum
	
	string fileName;
	inputFileName(fileName);
	fstream dataFile(fileName.c_str(), ios::in);
	dataFile>>year>>month>>day>>oldPrice;
	
	while(dataFile>>year>>month>>day>>price)
		{
	DR = dailyReturn(price, oldPrice);
	recordHighestDailyReturn(DR, highestDR, day, month, year, highDay, highMonth, highYear);
	recordSeasonalDailyReturn(month, DR, summerSum, summerC, fallSum, fallC, winterSum, winterC, springSum, springC);
	cout<<year<<" "<<month<<" "<<day<<" "<<price<<'\n';
	oldPrice = price;
		}
	outputResults(fileName, summerSum, summerC, fallSum, fallC, winterSum, winterC, springSum, springC, highestDR, highMonth, highDay, highYear);
	dataFile.close();
	return 0;
}

/**
*
*@brief  Asks the user to input the data file that will be used to collect data from.
*
*@param  fileName is passed through 
*
*/

void inputFileName(string& fileName)
{
	cout<<"Enter the DJIA file name: ";
	cin>>fileName;
}

/**
*
*@brief records and stores the daily return into the highest daily return, as well as storing the day, month, and year into the highDay, highMonth, and highYear variables
*
*@param  DR is passed through 
*@param  highestDR is passed through
*@param  day is passed through
*@param  month is passed through
*@param  year is passed through
*@param  highDay is passed through
*@param  highMonth is passed through
*@param  highYear is passed through
*
*/

void recordHighestDailyReturn(double& DR, double& highestDR, int& day, int& month, int& year, int& highDay, int& highMonth, int& highYear)
{
	if (DR>highestDR)
	{
		highestDR = DR;
		highDay = day;
		highMonth = month;
		highYear = year;
	}
	
}

/**
*
*@brief  Records the seasonal daily return for each of the four seasons in a year
*
*@param  month is passed through
*@param  DR is passed through
*@param  summerSum is passed through
*@param  summerC is passed thorugh
*@param  fallSum is passed through
*@param  fallC is passed through
*@param  winterSum is passed through
*@param  winterC is passed through
*@param  springSum is passed through
*@param  springC is passed through 
*
*/

void recordSeasonalDailyReturn(int& month, double& DR, double& summerSum, int& summerC, double& fallSum, int& fallC, double& winterSum, int& winterC, double& springSum, int& springC)
{
	if(month==6 || month==7 || month==8)
	{
		summerSum = summerSum + DR;
		summerC++;
	}
	else if(month==9 || month==10 || month==11)
	{
		fallSum = fallSum + DR;
		fallC++;
	}
	else if(month==3 || month==4 || month==5)
	{
		springSum = springSum + DR;
		springC++;
	}
	else if(month==12 || month==1 || month==2)
	{
		winterSum = winterSum + DR;
		winterC++;
	}
}

/**
*
*@brief  Calculates and displays to the user the percentages for seasonal daily returns and for the highest daily return
*
*@param  fileName is passed through 
*@param  summerSum is passed through
*@param  summerC is passed through
*@param  fallSum is passed thorugh
*@param  fallC is passed through
*@param  winterSum is passed through
*@param  winterC is passed through
*@param  springSum is passed through
*@param  springC is passed through
*@param  highestDR is passed through
*@param  highMonth is passed thorugh
*@param  highDay is passed through
*@param  highYear is passed through
*
*/

void outputResults(string& fileName, double& summerSum, int& summerC, double& fallSum, int& fallC, double& winterSum, int& winterC, double& springSum, int& springC, double& highestDR, int& highMonth, int& highDay, int& highYear)
{
	cout<<"Daily returns for the file name: "<<fileName;
	cout<<'\n';
	cout<<"Summer: "<<(summerSum/summerC)*100<<"%, Fall: "<<(fallSum/fallC)*100<<"%, Winter: "<<(winterSum/winterC)*100<<"%, Spring: "<<(springSum/springC)*100<<"%";
	cout<<'\n';
	cout<<"Highest Daily Return: "<<highestDR*100<<"%, on "<<highMonth<<"/"<<highDay<<"/"<<highYear<<'\n';
}

/**
*
*@brief  Calculates the daily return from the given data
*
*@param  price is passed through
*@param  oldPrice is passed through
*
*/

double dailyReturn(double& price, double& oldPrice)
{
	return(price/oldPrice-1);
}

