#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

char *readFile(void) {
  FILE *txtPtr;

  txtPtr = fopen("./messages.txt", "r");

  if (txtPtr == NULL) {
    printf("Erro: %s\n", strerror(errno));
  }

  char *myString = malloc(1024 * sizeof(char));

  if (fgets(myString, 1024, txtPtr) != NULL) {
    return myString;
  } else {
    free(myString);
    free(txtPtr);
    return NULL;
  }
}

int main(void) {
  char ipAddress[] = "127.0.0.1";
  int port = 43000;
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ipAddress);
  address.sin_port = htons(port);
  int result = bind(server_fd, (struct sockaddr *)&address, sizeof(address));

  if (result == 0) {
    printf("✅ Bind realizado com sucesso!\n\n");
  } else {
    printf("❌ Erro no bind!\n\n");
    perror("bind");
    return -1;
  }

  listen(server_fd, 3);

  printf("Server is running and listening on port %d...\n\n", port);

  while (1) {
    int addrlen = sizeof(address);
    int new_socket =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
      perror("Failed to accept connection\n");
      continue;
    }
    printf("connection accept\n");

    // char *response = "Ola do servidor TCP";
    // write(new_socket, response, strlen(response));

    char *menssagem = "";
    while (menssagem != NULL) {
      menssagem = readFile();
      printf("Menssagem: %s\n", menssagem);
      write(new_socket, menssagem, strlen(menssagem));
    }

    close(new_socket);
    printf("connection close");
  }

  close(server_fd);
  return 0;
}
