/**
* @file    Lab2.cpp
* @author  Jerry Housh (housga12)
* @date    01/31/2014
* @version 1.0 
*
* @brief   CSC 112, Lab 2, creates a dice game called craps, allows user to choose number of games and simulates that number of *	   games, displaying game/number of roles per game/wins and losses
*
* @section CSC 112. Dr. Fulp
*
*/

#include <iostream>
#include <cstdlib>
using namespace std; 

void inputNumberOfGames(int& userGames);
int rollDie();
void playGame(int& game, int& die1, int& die2, int& win, int& lose, int& point, int& rolls, bool& result);
void outputGameResult(int& game, int& rolls, bool result);
void outputGameStats(int& userGames, int& win, int& lose);

/**
*
*@brief  Defines a multitude of variables that will be used throughout the program
*
*@param  variables are defined
*@param	 five other functions defined and variables used in each function are entered in their parenthesis 
*
*/

int main()
{
	int userGames;	//Records the number of games the user wishes to play
	int game = 0;	//Used as a counter in order to terminate program once userGames is reached
	int die1 = 0;	//Holds number created by the random die generator
	int die2 = 0;	//Holds number created by the random die generator
	int win = 0;	//Records number of wins
	int lose = 0;	//Records number of losses
	int rolls = 0;	//Records number of rolls per game
	int point;	//Used to store the dice rolls in order to determine a win/loss in appropriate situation
	bool result;	//Records result of a single game (either win or loss)

inputNumberOfGames(userGames);
	for (game = 1; game <= userGames; game++) {
playGame(game, die1, die2, win, lose, point, rolls, result);
outputGameResult(game, rolls, result);
}

outputGameStats(userGames, win, lose);
}

/**
*@brief Displays a prompt to the user in order for the user to input the number of bulbs in their order
*
*@param	cout used to display prompt
*@param cin used to allow user to enter their number of bulbs
*
*/


void inputNumberOfGames (int& userGames)
{
	cout<<"Enter the number of games to play --> ";
	cin>>userGames;
}

/**
*
*@brief  Creates a random number between 1 and 6 (simulating a die roll)
*
*@param  Returns a random number between 1 and 6 when called upon 
*
*/

int rollDie()
{  return (rand()%6 + 1);  }

/**
*
*@brief  Simulates a single game of craps
*
*@param  Variables are defined and counters are used to store data displayed in the outputGameResult and outputGameStats functions
*@param	 if/else statements are used to determine a win or a loss 
*
*/

void playGame(int& game, int& die1, int& die2, int& win, int& lose, int& point, int& rolls, bool& result)
{
	rolls = 0;
	die1 = rollDie();
	die2 = rollDie();
	rolls++;
if ((die1 + die2) == 7 || (die1 + die2) == 11)
	{win++;
	result = true; 
	}
else if ((die1 + die2) == 2 || (die1 + die2) == 3 || die1 + die2 == 12)
	{lose++;
	result = false;
	}
else 
	
	{point = die1 + die2;
	die1 = rollDie();
	die2 = rollDie();
	rolls++;

while (point != (die1 + die2) && (die1 + die2) != 7) { 
	die1 = rollDie();
	die2 = rollDie();
	rolls++;
	}
if ((die1 + die2) == point)
	{win++;
	result = true;
	}
else if ((die1 + die2) == 7)
	{lose++;
	result = false;
	}
}			
}

/**
*
*@brief  Takes the data collected from playGame and displays the information correctly to the user
*
*@param  cout used to display games won and lost 
*
*/

void outputGameResult(int& game, int& rolls, bool result)
{
if (result){
	cout<<"Game "<<game<<" win, number of rolls "<<rolls<<'\n';
	}
else 
	cout<<"Game "<<game<<" loss, number of rolls "<<rolls<<'\n';
}

/**
*
*@brief  Displays the win percentage of wins out of total games played
*
*@param  cout displays total games, and out of that total, number of wins and losses
*@param	 cout displays the win percentage 
*
*/

void outputGameStats(int& userGames, int& win, int& lose)
{
	cout<<"Out of "<<userGames<<" games, won "<<win<<" and lost "<<lose<<'\n';
	double winPerc = (win/double (userGames));
	cout<<"Win percentage is "<<(winPerc)<<'\n';
}


		










