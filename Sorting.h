#include "ItemType.h"

#ifndef SORTING_H
#define SORTING_H

class Sorting {
public:
    long int numComparisons = 0;
	const int MAX = 10000;
	void swap(ItemType &first, ItemType &second); // swapping elements in values
	// methods for selection sort
	int minIndex(ItemType values[], int start, int end);
	void selectionSort(ItemType values[], int numValues);
	// methods for merge sort
	void mergeSort(ItemType values[], int first, int last);
	void merge(ItemType* values, int leftFirst, int leftLast, int rightFirst, int rightLast);
	// methods for quick sort
	void quickSort(ItemType values[], int first, int last);
	void split(ItemType values[], int first, int last, int &splitPoint);
	// methods for heap sort
	void heapSort(ItemType values[], int numValues);
	void reheapDown(ItemType values[], int root, int bottom);
	void print(ItemType values[]);
};
#endif
