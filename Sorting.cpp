#include <iostream>
#include "ItemType.h"
#include "Sorting.h"
#include <cstdlib>

using namespace std;

void Sorting::swap(ItemType &first, ItemType &second) {//function used to swap elements in array
	ItemType temp;
	temp = first;
	first = second;
	second = temp;
}

int Sorting::minIndex(ItemType values[], int start, int end) {
	int minIndex = start;
	for (int i = start + 1; i <= end; i++) {
		if (values[i].compareTo(values[minIndex]) == LESS) {
			minIndex = i;
	   numComparisons++;
		} // if
	} // for
	return minIndex;
}

void Sorting::selectionSort(ItemType values[], int numValues) {
	int end = numValues - 1;
	for (int i = 0; i < end; i++) {
		swap(values[i], values[minIndex(values, i, end)]);
	
	} // for
}

void Sorting::print(ItemType values[]) {
	for (int i = 0; i < MAX; i++) {
		values[i].print();
	} // for
}

void Sorting::mergeSort(ItemType values[], int first, int last){
  if (first < last){
    int middle = (first + last) / 2;
    mergeSort(values, first, middle);
    mergeSort(values, middle + 1, last);
    merge(values, first, middle, middle + 1, last);
  }//if
}

void Sorting::merge(ItemType* values, int leftFirst, int leftLast, int rightFirst, int rightLast){
  ItemType *temp = new ItemType[10000];
  int index = leftFirst;
  int saveFirst = leftFirst;
  
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
    if (values[leftFirst].compareTo(values[rightFirst]) == LESS){
      temp[index] = values[leftFirst];
      leftFirst++;
    }//if
    else{
      temp[index] = values[rightFirst];
      rightFirst++;
    }//else
    index++;
	numComparisons++;
  }//while
  
  while (leftFirst <= leftLast){
    temp[index] = values[leftFirst];
    leftFirst++;
    index++;
  }//while
  
  while (rightFirst <= rightLast){
    temp[index] = values[rightFirst];
    rightFirst++;
    index++;
  }//while
  
  for(index = saveFirst; index <= rightLast; index++){
    values[index] = temp[index];
  }//for
}

void Sorting::quickSort(ItemType values[], int first, int last){
	if (first < last) {
		int splitPoint;
		split(values, first, last, splitPoint);
		quickSort(values, first, splitPoint - 1);
		quickSort(values, splitPoint + 1, last);
	} // if
}

void Sorting::split(ItemType values[], int first, int last, int& splitPoint) {
	ItemType splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;
	first++;
	do {
		onCorrectSide = true;
		while (onCorrectSide) {
			if (values[first].compareTo(splitVal) == GREATER) {
				onCorrectSide = false;
			}
			else {
				first++;
				onCorrectSide = (first <= last);
			} // if
			numComparisons++;
		} // while
		onCorrectSide = (first <= last);
		while (onCorrectSide) {
			if ((values[last].compareTo(splitVal) == LESS) || (values[last].compareTo(splitVal) == EQUAL)) {
				onCorrectSide = false;
			}
			else {
				last--;
				onCorrectSide = (first <= last);
			} // if
			numComparisons++;
		} // while
		if (first < last) {
			swap(values[first], values[last]);
			first++;
			last--;
		} // if
	} while (first <= last); // do
	splitPoint = last;
	swap(values[saveFirst], values[splitPoint]);
}

void Sorting::heapSort(ItemType values[], int numValues){
  int index;
  for (index = (numValues/2) -1; index >= 0; index--){//make the heap
    reheapDown(values, index, numValues -1);
  }//for
  for (index = numValues -1; index >= 1; index--){//sort the heap
    swap(values[0], values[index]);
    reheapDown(values, 0, index -1);
  }//for
}

void Sorting::reheapDown(ItemType values[], int root, int bottom){
  int maxChild;
  int rightChild = (root*2) + 2;
  int leftChild = (root*2) + 1;
  
  if (leftChild <= bottom){
    if (leftChild == bottom){
      maxChild = leftChild;
    }//if
    else{
      if(values[leftChild].compareTo(values[rightChild]) == LESS || values[leftChild].compareTo(values[rightChild]) == EQUAL) {
        maxChild = rightChild;
      }//if
      else{
        maxChild = leftChild;
      }//else
      numComparisons++;
    }//else
    if (values[root].compareTo(values[maxChild]) == LESS){
      swap(values[root], values[maxChild]);
      reheapDown(values, maxChild, bottom);
    }//if
  }//if
}
