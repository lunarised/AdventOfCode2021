#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "test.text"

int partOne() {
  char input[1000];
  char* token;
  char states[9] = {{0}};
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(input, 1000, in_file);
  token = strtok(input, ",");
  while (token != NULL) {
    printf("%c", token);
    int fish = atoi(token);
    states[fish] += 1;
    token = strtok(NULL, ",");
  }

  return states[3];
}

int main() {
  printf("%d", partOne());
  return EXIT_SUCCESS;
}