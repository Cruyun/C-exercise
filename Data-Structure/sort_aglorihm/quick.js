function partition(arr, low, high) {
  let pivot = arr[high];
  let i = low - 1;
  for (let j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }
  [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
  return i + 1;
}

function quickSort(arr, low, high) {
  if (low < high) {
    let pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

function finKthLargest(arr, k) {
  let l = 0;
  let h = arr.length - 1;
  k = arr.length - k;
  while (l < h) {
    let pivot  = partition(arr, l, h);
    if (pivot < k) {
      l = pivot + 1;
    } else if (pivot > k) {
      h = pivot - 1;
    } else {
      break;
    }
  }
  return arr[k];
}
var arr = [1,5,7,3,4,8];
quickSort(arr, 0, 5);
console.log(arr);

console.log(finKthLargest(arr, 2))