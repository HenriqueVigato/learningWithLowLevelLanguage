#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arrayNumeros = (int *)malloc(10 * sizeof(int));

  arrayNumeros[0] = 1;
  arrayNumeros[1] = 2;
  arrayNumeros[9] = 3;

  for (int i = 0; i < 10; i++) {
    printf("%d\n", arrayNumeros[i]);
  }

  free(arrayNumeros);
  return 0;
}
