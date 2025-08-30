#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

void merge_sort(int a[], int length) {
  merge_sort_recursion(a, 0, length - 1);
};

void merge_sort_recursion(int a[], int l, int r) {
  if (l < r) {
    int m = l - (l - r) / 2;
    merge_sort_recursion(a, 0, m);
    merge_sort_recursion(a, m + 1, r);
    merge(a, l, m, r);
  }
}

void merge(int a[], int l, int m, int r) {
  int i, j, k;
  int size_l = m - l + 1;
  int size_r = r - m;

  int temp_l[size_l];
  int temp_r[size_r];

  for (int i = 0; i < size_l; i++) {
    temp_l[i] = a[l + i];
  }

  for (int i = 0; i < size_r; i++) {
    temp_r[i] = a[m + 1 + i];
  }

  for (i = 0, j = 0, k = l; k <= r; k++) {
    if ((i < size_l) && (j >= size_r || temp_l[i] < temp_r[j])) {
      a[k] = temp_l[i];
      i++;
    } else {
      a[k] = temp_r[j];
      j++;
    }
  }
}

int main() {

  int array[] = {7, 3, 6, 4, 5, 9, 1, 2, 8, 10};
  int arrayLength = 10;

  for (int i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  merge_sort(array, arrayLength);

  for (int i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
