#include <iostream>
using namespace std;
void binary_search(int arr[], int low, int high, int min, int max);

int main()
{
	int a[11] = {1,5,6,7,10,14,15,17,19,20,30};
  int min, max;
  cin >> min >> max;
  binary_search(a, 0, 10, min, max);

	return 0;
}

void binary_search(int arr[], int low, int high, int min, int max) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= min) {
        binary_search(arr, mid, high, min, max);
    } else if (arr[mid] >= max) {
        binary_search(arr, low, mid, min, max);
    } else {
      for (int i = mid; arr[i] >= min && i >= low; i--) {
        cout << arr[i] << " ";
      }
      for (int j = mid + 1; arr[j] <= max && j <= high; j++) {
        cout << arr[j] << " ";
      }
    }
}