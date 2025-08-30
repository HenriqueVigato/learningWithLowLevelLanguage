#include <stdio.h>

void quick_sort(int arr[], int length);
void quick_sort_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *x, int *y);

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quick_sort(int arr[], int length) {
  quick_sort_recursion(arr, 0, length - 1);
}

void quick_sort_recursion(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quick_sort_recursion(arr, low, pivot - 1);
    quick_sort_recursion(arr, pivot + 1, high);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[high]);
  return i;
}

int main() {
  int a[] = {17, 42, 8,  33, 55, 12, 29, 4,  61, 21, 38, 7,  50, 19,
             45, 15, 31, 10, 58, 25, 49, 14, 36, 3,  63, 23, 47, 11,
             52, 27, 41, 6,  60, 20, 44, 18, 35, 9,  56, 22, 48, 13,
             34, 5,  59, 24, 46, 16, 39, 2,  54, 26, 40, 1};

  int length = 54;

  quick_sort(a, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
