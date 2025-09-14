#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

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
    printf("✅ Bind realizado com sucesso!\n");
  } else {
    printf("❌ Erro no bind!\n");
    perror("bind");
    return -1;
  }

  listen(server_fd, 3);

  printf("Server is running and listening on port %d...\n", port);

  while (1) {
    int addrlen = sizeof(address);
    int new_socket =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
      perror("Failed to accept connection");
      continue;
    }
    printf("connection accept");

    char *response = "Ola do servidor TCP";
    write(new_socket, response, strlen(response));

    close(new_socket);
    printf("connection close");
  }

  close(server_fd);
  return 0;
}
