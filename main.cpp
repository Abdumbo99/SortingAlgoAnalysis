
/* *
* Title : Algorithm Efficiency and Sorting
* Author : Abdul Razak Daher Khatib
* ID : 21801340
* Section : 001
* Assignment : 1
* Description : Here I have the sorting algorithms main driver which will perform the mandatory tasks and print the analysis 
*/
#include "sorting.h"


int main() {

	sorting s;
	int array[]= { 1, 100, 57, 92, 43, 99, 93, 17, 58 };
	int array01[] = { 1, 100, 57, 92, 43, 99, 93, 17, 58 };
	int array02[] = { 1, 100, 57, 92, 43, 99, 93, 17, 58 };
	s.quickSort(array, 0, 8, s.compCount,s.moveCount);
	s.printArray(array, 9);
	s.insertionSort(array01,9 ,s.compCount, s.moveCount);
	s.printArray(array01, 9);
	s.hybridSort(array02, 9 ,s.compCount, s.moveCount);
	s.printArray(array02, 9);
	s.performanceAnalysis();
}
