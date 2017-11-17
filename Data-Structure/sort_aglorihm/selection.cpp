#include <iostream>
using namespace std;

void selection_sort(int arr[], int length) {
	int temp;
	for (int i = 1; i < length; i++) {
		int j = i;
		for ( int k = i + 1; k <= length; k++) {
			if (arr[k] < arr[j]) {
				j = k;
			}
			if ( j != i) {
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		cout << i << ":" << arr[i] << endl;
	}	
}

