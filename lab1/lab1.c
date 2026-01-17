#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *buff = NULL;
  size_t size = 0;

  while (1) {
    printf("put any text: ");
    fflush(stdout);

    ssize_t n = getline(&buff, &size, stdin);
    if (n == -1) {
      break;
    }
    printf("Tokens:\n");

    char *saveptr = NULL;
    char *tok = strtok_r(buff, " \n", &saveptr);

    while (tok != NULL) {
      printf("    %s\n", tok);
      tok = strtok_r(NULL, " \n", &saveptr);
    }
  }

  free(buff);
  return 0;
}
