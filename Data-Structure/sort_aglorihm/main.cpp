#include <iostream>
#include "quick.cpp"
#include "insertion.cpp"
#include "selection.cpp"
using namespace std;

int main() {
	int arr[7] = {5, 7, 3, 4, 2, 8, 6};
	int length = 7;
	quick_sort(arr, 0, length-1);
	// insertion_sort(arr, length);
	//selection_sort(arr,length);
	for (int i = 0; i < length; i++) {
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}

	return 0;
}
