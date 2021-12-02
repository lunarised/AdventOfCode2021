#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int xPos = 0;
  int yPos = 0;
  int value;
  char line[100];
  char* command;
  FILE* in_file = fopen("input.text", "r");

  while (fgets(line, 100, in_file) != NULL) {
    command = strtok(line, " ");
    value = atoi(strtok(NULL, " "));
    if (strcmp(command, "forward") == 0) {
      xPos += value;
    }
    if (strcmp(command, "up") == 0) {
      yPos += value;
    }
    if (strcmp(command, "down") == 0) {
      yPos -= value;
    }
  }
  printf("%d", abs(xPos * yPos));

  return EXIT_SUCCESS;
}