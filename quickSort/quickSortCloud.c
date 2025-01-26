#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int array[], int low, int high) {
  int pivo = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivo) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
  int n = sizeof(array) / sizeof(array[0]);

  printf("Array origina\n");
  printArray(array, n);

  quickSort(array, 0, n - 1);

  printf("\nArray ordenado: \n");
  printArray(array, n);

  return 0;
}
