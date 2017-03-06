/**
* @file    lab1.cpp
* @author  Jerry Housh (housga12)
* @date    01/24/2014
* @version 1.0 
*
* @brief   CSC 112, Lab 1, gets input on shipment of bulbs from *          user, calculates the prices and number of sized boxes to *	   ship with, and displays the calculations to the user     		   through output functions.
*
* @section CSC 112. Dr. Fulp
*
*/

#include <iostream>
using namespace std;

void inputOrder(int& numbBulbs, int& numBulbs);
void calcOrder(int& numBulbs, int& huge, int& large, int& medium, int& small, double& costCon, double& costBulbs, double& totalCost);
void outputOrder(int&numbBulbs, int& numBulbs, int& huge, int& large, int& medium, int& small, double& costCon, double& costBulbs, double& totalCost);

/**
*
*	@brief  Defines a multitude of variables that will be used *		throughout the program
*
*	@param  variables are defined
*	@param	three other functions defined and variables used in *		each function are entered in their parenthesis 

*/

int main()
{
	int numbBulbs;		//Created to store user input number
	int numBulbs;		//Allows for calculation of sizes
	int huge;		//Largest size for shipment
	int large;		//Second largest size for shipment
	int medium;  		//Third largest size
	int small;		//Smallest size
	double costCon;		//stores the total cost of containers
	double costBulbs;	//stores the total cost of bulbs
	double totalCost;	//stores total cost of shipment

inputOrder(numbBulbs, numBulbs);
calcOrder(numBulbs,huge,large,medium,small,costCon,costBulbs, totalCost);
outputOrder(numbBulbs, numBulbs, huge, large, medium, small, costCon, costBulbs, totalCost);

return 0;
}

/**
*	@brief  Displays a prompt to the user in order for the user *		to input the number of bulbs in their order
*
*	@param	cout used to display prompt
*	@param  cin used to allow user to enter their number of bulbs
*
*/

void inputOrder (int& numBulbs, int&numbBulbs)
{
cout<<"Enter the number of lightbulbs in the order: ";
cin >> numBulbs;
numbBulbs = numBulbs;
}

/**
*	@brief given the user's input, various calculations are made 
*	       in order to arrive at information that is beneficial *	       to the user
*
*	@param creates more variables in order to assist with *	       calculations
*/

void calcOrder (int& numBulbs, int& huge, int& large, int& medium, int& small, double& costCon, double& costBulbs, double& totalCost)
{

double cHuge;	//stores cost of huge boxes
double cLarge;	//stores cost of large boxes
double cMedium;	//stores cost of medium boxes
double cSmall;	//stores cost of small boxes

costBulbs = numBulbs*1.55;
huge = numBulbs/20;
numBulbs = numBulbs%20;
large = numBulbs/15;
numBulbs = numBulbs%15;
medium = numBulbs/7;
numBulbs = numBulbs%7;
small = numBulbs/1;
numBulbs = numBulbs%1;


cHuge = huge*5.00;
cLarge = large*3.50;
cMedium = medium*2.00;
cSmall = small*0.75;

costCon = cHuge+cLarge+cMedium+cSmall; 

totalCost = costCon+costBulbs;
}

/**
*	@brief Displays useful information that was calculated in *	       the previous function to the user.
*
*/

void outputOrder (int& numbBulbs, int& numBulbs, int& huge, int& large, int& medium, int& small, double& costCon, double& costBulbs, double& totalCost)
{
	cout<<"Shipment schedule for  "<<numbBulbs<<" bulbs.\n";
	cout<<"---------------------------------\n";
	cout<<"Number of containers required:\n";
	cout<<"Huge: "<<huge<<'\n';
	cout<<"Large: "<<large<<'\n';
	cout<<"Medium: "<<medium<<'\n';
	cout<<"Small: "<<small<<'\n';
	cout<<"Cost of the light bulbs: $"<<costBulbs<<'\n';
	cout<<"Cost of the containers: $"<<costCon<<'\n';
	cout<<"Total cost of order: $"<<totalCost;
}

