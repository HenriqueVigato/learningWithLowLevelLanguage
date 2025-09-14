#include <errno.h>
#include <stdio.h>
#include <string.h>

int printing_to_the_end(FILE *textPtr) {
  char myString[180] = "";
  char myMessage[9];
  while (fgets(myMessage, 9, textPtr) != NULL) {
    char *quebra = strchr(myMessage, '\n');

    if (quebra != NULL) {
      *quebra = '\0';
      strcat(myString, myMessage);
      printf("read: %s\n", myString);
      myString[0] = '\0';
    } else {
      strcat(myString, myMessage);
    }
  }
  return 0;
}

int getFromFile() {
  FILE *txtPtr;
  txtPtr = fopen("./messages.txt", "r");

  if (txtPtr == NULL) {
    printf("Erro: %s\n", strerror(errno));
  }
  printing_to_the_end(txtPtr);

  fclose(txtPtr);
  return 0;
}

int main() {
  getFromFile();
  return 0;
}
