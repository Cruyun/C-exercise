#include <iostream>
//#include "insertion.cpp"
#include "selection.cpp"
using namespace std;

int main() {
	int arr[7] = {9, 7, 3, 4, 2, 8, 1};
	int length = 7;
	selection_sort(arr,length);
	for (int i = 0; i < length; i++) {
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}

	return 0;
}
