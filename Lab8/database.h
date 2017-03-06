/**
* @file    lab8.cpp
* @author  Jerry Housh (housga12)
* @date    03/28/2014
* @version 1.0 
*
* @brief   This program takes values from a database and organizes said values in ascending order.  
*	   The program also removes multiples of the same value and prints the final database ID's out line by line. 
*	   Dynamic arrays, as opposed to static arrays, are used and an improved while loop is used in 
*	   the search function in order to speed up the program and make it more efficient. 
*
* @section CSC 112. Dr. Fulp
*
*/

#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
using namespace std;

int search(int value, int list[], int n);
void addValue(int value, int*& list, int& n);
void deleteValue(int loc, int*& list, int& n);
void printValues(int& n, int list[], char* fileName);
#endif
