#include <errno.h>
#include <stdio.h>
#include <string.h>

int printing_to_the_end(FILE *textPtr) {
  char myMessage[9];
  while (fgets(myMessage, 9, textPtr) != NULL) {
    printf("%s\n", myMessage);
  }
  return 0;
}

int main() {
  FILE *txtPtr;
  txtPtr = fopen("./messages.txt", "r");

  if (txtPtr == NULL) {
    printf("Erro: %s\n", strerror(errno));
  }

  // char myMessage[8];
  // fgets(myMessage, 8, txtPtr);
  //
  // printf("%s\n", myMessage);
  printing_to_the_end(txtPtr);

  fclose(txtPtr);
  return 0;
}
