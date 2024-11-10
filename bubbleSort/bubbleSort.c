#include <stdio.h>

void sort(int *array, int sizeOfArray) {
  int temp = 0;
  for (int i = 0; i < sizeOfArray; i++) {
    for (int j = 0; j < sizeOfArray; j++) {
      if (array[j] > array[i]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
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
