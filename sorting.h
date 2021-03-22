/* *
* Title : Algorithm Efficiency and Sorting
* Author : Abdul Razak Daher Khatib
* ID : 21801340
* Section : 001
* Assignment : 1
* Description : Here I have the sorting algorithms and print and analysis algorithms headers
*/

#ifndef __SORTING__H
#define __SORTING__H
#include <string>
#include <iostream>
#include <ctime>
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
#include <iomanip>
using namespace std;
class sorting {
public:
	void quickSort(int* arr, int f, int l, int& compCount, int& moveCount);
	void insertionSort(int* arr, int size, int& compCount, int& moveCount);
	void hybridSort(int* arr, int size, int& compCount, int& moveCount);
	void printArray(int* arr, int size);
	int partition(int* arr, int fir, int last,  int& compCount, int& moveCount);
	void performanceAnalysis();
	int moveCount =0 ;
	int compCount =0;


};

#endif
