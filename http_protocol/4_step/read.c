#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

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
  char *buffer = malloc(8 * sizeof(char));
  while (1) {
    int dataReceived = recv(client, buffer, 8, MSG_DONTWAIT);

    if (dataReceived < 0) {
      break;
    } else if (dataReceived == 0) {
      break;
    }

    char *newLine = strchr(buffer, '\n');
    if (newLine != NULL) {
      *newLine = '\0';
      printf("%s", buffer);
      printf("\n");
      printf("read: %s", newLine + 1);
    } else {
      printf("%s", buffer);
    }
  }
}

int main() {
  char addr[] = "127.0.0.1";
  int port = 43000;

  int clientConnection = tcpClient(addr, port);
  printf("read: ");
  printData(clientConnection);

  close(clientConnection);
  printf("Conexao Fechada\n");

  return 0;
}
