#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd < 0) {
    perror("Socket criation falied");
    return -1;
  }

  struct sockaddr_in server_addres;
  server_addres.sin_family = AF_INET;
  server_addres.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addres.sin_port = htons(43000);

  if (connect(client_fd, (struct sockaddr *)&server_addres,
              sizeof(server_addres)) < 0) {
    perror("Connection failed");
    close(client_fd);
    return -1;
  }

  printf("Connection succed!\n");

  char buffer[1024] = {0};
  int bytes_received = read(client_fd, buffer, 1024);
  if (bytes_received) {
    printf("Server message: %s\n", buffer);
  }

  close(client_fd);
  printf("Conexao fechada\n");

  return 0;
}
