#include "read.h"
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int tcpClient(const char *addr, const int port) {
  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd < 0) {
    perror("socket criation failed!");
    return -1;
  }

  struct sockaddr_in server_addres;
  server_addres.sin_family = AF_INET;
  server_addres.sin_addr.s_addr = inet_addr(addr);
  server_addres.sin_port = htons(port);

  if (connect(client_fd, (struct sockaddr *)&server_addres,
              sizeof(server_addres)) < 0) {
    perror("Connection failed");
    close(client_fd);
    return -1;
  } else {
    printf("Connection succed! \n");
  }

  return client_fd;
}

void printData(int client) {
  char *buffer = malloc(9 * sizeof(char));
  while (1) {
    // limpa o buffer para nao ter nada
    memset(buffer, 0, 9 * sizeof(char));

    int dataReceived = recv(client, buffer, (9 * sizeof(char)) - 1, 0);
    if (dataReceived < 0) {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        printf("\nBuffer do sistema vazio!\n");
      } else {
        perror("Erro no recv");
        free(buffer);
      }
      break;
    } else if (dataReceived == 0) {
      free(buffer);
      break;
    }

    char *newLine = strchr(buffer, '\n');
    if (newLine != NULL) {
      *newLine = '\0';
      printf("%s", buffer);
      printf("\n");
      printf("read: %s", newLine + 1);
      fflush(stdout);
    } else {
      printf("%s", buffer);
      fflush(stdout);
    }
  }
}

int test(void) {
  int numero = 1;
  int num = 5;

  return numero + num;
}

#ifndef TESTING
int main() {
  char addr[] = "127.0.0.1";
  int port = 43000;

  int clientConnection = tcpClient(addr, port);
  printf("read: ");
  fflush(stdout);
  printData(clientConnection);

  close(clientConnection);
  printf("Conexao Fechada\n");

  return 0;
}
#endif
