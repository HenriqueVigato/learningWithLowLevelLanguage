#include <stdio.h>

void mergeSortRecursion(int a[], int l, int r);
void mergeSort(int array[], int size);
void merge(int a[], int l, int m, int r);

void mergeSort(int array[], int size) {
  mergeSortRecursion(array, 0, size - 1);
};

void mergeSortRecursion(int a[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSortRecursion(a, l, m);
    mergeSortRecursion(a, m + 1, r);

    merge(a, l, m, r);
  }
};

void merge(int a[], int l, int m, int r) {
  int leftSize = m - l + 1;
  int rightSize = r - m;

  int arrLeft[leftSize];
  int arrRight[rightSize];

  int i, j, k;

  for (int i = 0; i < leftSize; i++) {
    arrLeft[i] = a[l + i];
  }
  for (int j = 0; j < rightSize; j++) {
    arrRight[j] = a[m + 1 + j];
  }

  for (i = 0, j = 0, k = l; k <= r; k++) {
    if ((i < leftSize) && (j >= rightSize || arrLeft[i] <= arrRight[j])) {
      a[k] = arrLeft[i];
      i++;
    } else {
      a[k] = arrRight[j];
      j++;
    }
  };
}

int main() {
  int array[15] = {43, 27, 89, 12, 55, 76, 31, 94, 8, 67, 22, 15, 83, 49, 60};
  int size = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  mergeSort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
