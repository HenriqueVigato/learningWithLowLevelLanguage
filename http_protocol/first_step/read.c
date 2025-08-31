#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *txtPtr;
  txtPtr = fopen("./messages.txt", "r");

  if (txtPtr == NULL) {
    printf("Erro: %s\n", strerror(errno));
  }

  char myMessage[8];
  fgets(myMessage, 8, txtPtr);

  printf("%s\n", myMessage);

  fgets(myMessage, 8, txtPtr);
  printf("%s\n", myMessage);

  fclose(txtPtr);
}
