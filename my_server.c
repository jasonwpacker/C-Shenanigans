#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
  int my_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in my_addr = {
    AF_INET, 0x901f, 0
  };
  bind(my_socket, &my_addr, sizeof(my_addr));
  listen(my_socket, 8);
  int client_fd = accept(my_socket, 0, 0);

  char buffer[512] = {0};
  recv(client_fd, buffer, 512, 0);
  printf("%s\n", buffer);
  char *file_name = buffer+5;
  strchr(file_name, ' ')[0] = 0;
  printf("%s\n", file_name);

  close(client_fd);
  close(my_socket);

}
