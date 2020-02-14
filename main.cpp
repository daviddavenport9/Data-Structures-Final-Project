#include "ItemType.h"
#include "Sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[]) {
	Sorting sort;
	const int MAX = 10000;
	bool terminate = false;
	ItemType values[MAX];
	ItemType item;
	int index = 0;
	fstream fs;
	int input;
	fs.open(argv[1], fstream::in);
	if (fs.is_open()) {
		fs >> input;
		while (!fs.eof()) {
			item.initialize(input);
			values[index] = item;
			index++;
			fs >> input;
		} // while
	}//if
	else {
		cout << "Failed to open the input file" << endl;
		return 0;
	} // else
	char command;
	while (!terminate) {
		cout << "selection-sort (s)\tmerge-sort (m)\theap-sort (h)\tquick-sort-fp (q)\t quick-sort-rp (r)" << endl;
		cout << "Enter the algorithm: ";
		cin >> command;
		if (command == 's') { // selection sort
			sort.selectionSort(values, MAX);
			sort.print(values);
			cout << "" << endl;
			cout << "#Selection-sort comparisons: " << sort.numComparisons << endl;
			terminate = true;
		} // if
		else if (command == 'm') { // merge sort
			sort.mergeSort(values, 0, MAX - 1);
			sort.print(values);
			cout << "" << endl;
			cout << "#Merge-sort comparisons: " << sort.numComparisons << endl;
			terminate = true;
		} // if
		else if (command == 'h') { // heap sort
			sort.heapSort(values, MAX);
			sort.print(values);
			cout << "" << endl;
			cout << "#Heap-sort comparisons: " << sort.numComparisons << endl;
			terminate = true;
		} // if
		else if (command == 'q') { // quick sort first pivot
			sort.quickSort(values, 0, MAX - 1);
			sort.print(values);
			cout << "" << endl;
			cout << "#Quick-sort-fp comparisons: " << sort.numComparisons << endl;
			terminate = true;
		} // if 
		else if (command == 'r') { // quick sort random pivot
			random_shuffle(&values[0], &values[MAX]); // first shuffle array
			sort.quickSort(values, 0, MAX - 1);
			sort.print(values);
			cout << "" << endl;
			cout << "#Quick-sort-rp comparisons: " << sort.numComparisons << endl;;
			terminate = true;
		} // if
		else {
			cout << "Command not recognized. Please try again." << endl;
		} // if
	} // while
	return EXIT_SUCCESS;
}
