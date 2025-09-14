#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(43000);
  int result = bind(server_fd, (struct sockaddr *)&address, sizeof(address));

  if (result == 0) {
    printf("✅ Bind realizado com sucesso!\n");
  } else {
    printf("❌ Erro no bind!\n");
    perror("bind");
    return -1;
  }

  listen(server_fd, 3);
}
