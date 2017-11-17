#include <iostream>
#include "selection.cpp"
using namespace std;

int main() {
	int arr[7] = {9, 7, 3, 4, 2, 8, 1};
	int length = 7;
	selection_sort(arr,length);
	return 0;
}
