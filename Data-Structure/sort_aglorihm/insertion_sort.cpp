#include <iostream>
using namespace std;

void insertion_sort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			for (j = i - 1; temp < arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
