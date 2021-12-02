#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int partOne() {
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
  return abs(xPos * yPos);
}

int partTwo() {
  int xPos = 0;
  int yPos = 0;
  int aim = 0;
  int value;
  char line[100];
  char* command;
  FILE* in_file = fopen("input.text", "r");

  while (fgets(line, 100, in_file) != NULL) {
    command = strtok(line, " ");
    value = atoi(strtok(NULL, " "));
    if (strcmp(command, "forward") == 0) {
      xPos += value;
      yPos += (aim * value);
    }
    if (strcmp(command, "up") == 0) {
      aim += value;
    }
    if (strcmp(command, "down") == 0) {
      aim -= value;
    }
  }
  return abs(xPos * yPos);
}

int main() {
  printf("%d\n", partOne());
  printf("%d\n", partTwo());
  return EXIT_SUCCESS;
}