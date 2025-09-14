#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;
  ssize_t num_char;
  printf("Please enter some text: ");
  num_char = getline(&buffer, &size, stdin);

  if (num_char == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }

  printf("Tokens:\n");

  char *saveptr;
  char *token = strtok_r(buffer, " ", &saveptr);

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(buffer);

  return 0;
}
