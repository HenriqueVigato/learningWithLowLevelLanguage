#include <stdio.h>

void sort(int *array, int sizeOfArray) {
  int temp, min;

  for (int i; i < sizeOfArray; i++) {
    min = array[i];

    for (int j; j < sizeOfArray; i++) {
      if (array[j] < array[i]) {
        min = array[j];
      }
    }
  }
}

int main() {
  int listaParaOrdenar[10] = {9, 1, 3, 5, 2, 7, 4, 8, 6, 0};

  for (int i = 0; i < 10; i++) {
    printf("%d, ", listaParaOrdenar[i]);
  }
  printf("\n\n");

  sort(listaParaOrdenar, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d, ", listaParaOrdenar[i]);
  }
  printf("\n\n");

  return 0;
}
