#include <iostream>
using namespace std;

void insertion_sort(int arr[], int length) {
	int j, key;
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			key  = arr[i];
			for (j = i - 1; key < arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = key;
		}
	}
}
