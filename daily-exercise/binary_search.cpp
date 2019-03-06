// recursion version
int binary_search(const int arr[], int start, int end, int key) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] > key) {
        return binary_search(arr, mid - 1, end, key);
    }
    if (arr[mid] < key) {
        return binary_search(arr, mid + 1, end, key);
    }
    return mid;
}

// while loop version
int binary_search(const int arr[], int start, int end, int key) {
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] < key) {
            start = mid + 1;
        }
        else if (arr[mid] > key) {
            start = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}