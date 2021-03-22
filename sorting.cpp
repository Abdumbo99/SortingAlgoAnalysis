/* *
* Title : Algorithm Efficiency and Sorting
* Author : Abdul Razak Daher Khatib
* ID : 21801340
* Section : 001
* Assignment : 1
* Description : Here I have the sorting algorithms and print and analysis algorithms definition
*/

#include "sorting.h"
#include <ctime>

void sorting::quickSort(int* arr, int f, int l, int& compCount, int& moveCount) {

	if (f < l) {
		int pivotInd = partition(arr, f, l, compCount, moveCount); //call partition and return pivot
		quickSort(arr, f, pivotInd - 1, compCount, moveCount);//call quicksort on everything before the pivot
		quickSort(arr, pivotInd + 1, l, compCount, moveCount); //call quicksort on everything after the pivot
	}
}

void sorting::insertionSort(int* arr, int size, int& compCount, int& moveCount) {
	
	for (int i = 0; i < size; i++) {
		int nextInt = arr[i]; moveCount++; // save next element temporarily
		int cur = i; //save index of current
		for (; (cur > 0) && (arr[cur - 1] > nextInt); cur--) {
			compCount++;
			arr[cur] = arr[cur - 1]; moveCount++; // shift the element if if it is biggger than than next element
		}
		arr[cur] = nextInt; moveCount++; // put element in its place
	}
}

void sorting::hybridSort(int* arr, int size, int& compCount, int& moveCount) {
	int pivotIndex;
	if (size <= 10) 
		insertionSort(arr, size, compCount, moveCount ); // if less than 10 call insertion
	else {
		int lInd = size - 1; // defining index for quick sort
		pivotIndex = partition(arr, 0, lInd, compCount, moveCount); 
		int tempSize1 = pivotIndex + 1;  // first index for next call
		int tempSize2 =  size - pivotIndex - 1; // second index for next call
		hybridSort(arr, tempSize1 , compCount, moveCount);
		hybridSort(arr + tempSize1 , tempSize2 , compCount, moveCount);
	}

}

int sorting::partition(int* arr, int fir, int last,  int& compCount, int& moveCount) {

	int frInd, lastSortedInd; //indices
	int pivot;
	lastSortedInd = fir; 
	pivot = arr[fir]; moveCount++;
	frInd = fir + 1;
	for (; frInd <= last; frInd++ ) {
		if (arr[frInd] < pivot) {
			compCount++;
			lastSortedInd++;
			//next three line are swap
			int temp = arr[lastSortedInd]; moveCount++; 
			arr[lastSortedInd] = arr[frInd]; moveCount++;
			arr[frInd] = temp; moveCount++;
		}
	}
	// another swap between first element (pivot) and the last sorted
	int temp1 = arr[fir]; moveCount++;
	arr[fir] = arr[lastSortedInd]; moveCount++;
	arr[lastSortedInd] = temp1; moveCount++;
	return lastSortedInd;
}

void sorting::printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) 
		cout << arr[i]<<"\t";
	
	cout<<""<<endl;
}

void sorting::performanceAnalysis() {
	double duration ;
	int rowCount = 10; // 10 arrrays to analyse
	int tempSize;
	// create three two deminsional arrays to save the 10 arrays to analyse
	int** arr = new int* [rowCount];
	int** arr01 = new int* [rowCount];
	int** arr02 = new int* [rowCount];
	// define sizes
	for (int i = 0; i <= 10; i++) {
		tempSize = 10000 + (i * 2000); 
		arr[i] = new int[tempSize];
		arr01[i] = new int[tempSize];
		arr02[i] = new int[tempSize];
	//fill arrays
	for (int j = 0; j < tempSize; j++) 
		arr01[i][j] = arr02[i][j] = arr[i][j] = rand();
					
	}
	cout << "-----------------------------------------------------" << endl;
	cout << "Part a - Time analysis of Quick Sort" << endl;
	cout <<left << "Array Size" <<left << "\t\tTime Elapsed (ms)" << left <<"\t\tcompCount" << left << "\t\tmoveCount" << endl;
	moveCount = compCount = 0;

	for (int i = 0; i <= 10; i++) {
		tempSize = 10000 + (i * 2000);
		clock_t startTime = clock(); // start calculating time
		quickSort(arr02[i], 0, tempSize - 1, compCount, moveCount);
		///cout << tempSize << "\t \t" <<   "ms\t\t" << moveCount << "\t\t" << compCount << endl;
		duration = tempSize * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout <<  left <<tempSize << left<< "\t\t\t"<< duration <<  left << "\t\t\t\t"<<compCount<< "\t\t\t"<< left <<moveCount << endl;
		moveCount = compCount = 0;
	}	
	cout << "-----------------------------------------------------" << endl;
	cout << "Part b - Time analysis of Insertion Sort" << endl;
	cout <<left << "Array Size" <<left << "\t\tTime Elapsed (ms)" << left <<"\t\tcompCount" << left << "\t\t\tmoveCount" << endl;
		
	for (int i = 0; i <= 10; i++) {
		tempSize = 10000 + (i * 2000);
		clock_t startTime = clock(); // start calculating time
		insertionSort(arr01[i], tempSize, compCount, moveCount);
		duration = tempSize * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout <<  left <<tempSize << left<< "\t\t\t"<< duration <<  left << "\t\t\t\t"<<compCount<< "\t\t\t"<< left <<moveCount << endl;
		moveCount = compCount = 0;
	}
	cout << "-----------------------------------------------------" << endl;
	cout << "Part c - Time analysis of Hybrid Sort" << endl;
	cout <<left << "Array Size" <<left << "\t\tTime Elapsed (ms)" << left <<"\t\tcompCount" << left << "\t\tmoveCount" << endl;

	for (int i = 0; i <= 10; i++) {
		tempSize = 10000 + (i * 2000);
		clock_t startTime = clock(); // start calculating time
		hybridSort(arr[i], tempSize, compCount, moveCount);
		duration = tempSize * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout <<  left <<tempSize << left<< "\t\t\t"<< duration <<  left << "\t\t\t\t"<<compCount<< "\t\t\t"<< left <<moveCount << endl;
		moveCount = compCount = 0;
	}
}
