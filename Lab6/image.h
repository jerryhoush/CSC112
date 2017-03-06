#include <iostream>
#include <fstream>
#include "jpeg.h"
using namespace std;

void shrinkImage(unsigned char image[][MAX_COL], int&nRow, int&nCol);
void convertImage(unsigned char image[][MAX_COL], int&nRow, int&nCol, char ascii[][100]);
void writeImage(string textFileName, char ascii[][100], int& nRow, int& nCol);
