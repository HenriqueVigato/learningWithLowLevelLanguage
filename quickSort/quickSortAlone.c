#include <stdio.h>

void quickSort(int a[], int length);
void quickSortRecursion(int a[], int low, int high);
void swap(int *x, int *y);
int naoSeiNome(int a[], int low, int high);

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quickSort(int a[], int length) { quickSortRecursion(a, 0, length - 1); }

void quickSortRecursion(int a[], int low, int high) {
  if (low < high) {
    int pivot = naoSeiNome(a, low, high);
    quickSortRecursion(a, low, pivot - 1);
    quickSortRecursion(a, pivot + 1, high);
  }
}

int naoSeiNome(int a[], int low, int high) {
  int pivot = a[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (a[j] < pivot) {
      swap(&a[i], &a[j]);
      i++;
    }
  }
  swap(&a[i], &a[high]);
  return i;
}

int main() {
  int a[] = {12, 65, 36, 57, 896, 3, 89, 6987, 45, 23, 2, 2, 1, 0, 035, 45};
  int length = 16;

  quickSort(a, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
