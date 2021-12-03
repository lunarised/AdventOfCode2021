#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Command {
  int command;
  int arg;
};

enum commandType
{
  forward,
  up,
  down
};

int stringToCommand(char* cmdString){
  if (strcmp("forward", cmdString) == 0){
    return forward;
  }
   else if (strcmp("up", cmdString) == 0){
    return up;
  }
   else if (strcmp("down", cmdString) == 0){
    return down;
  }
}

int partOne() {
  int xPos = 0;
  int yPos = 0;
  int value;
  struct Command c;
  char line[100];
  FILE* in_file = fopen("input.text", "r");

  while (fgets(line, 100, in_file) != NULL) {

    c.command = stringToCommand(strtok(line, " "));
    c.arg = atoi(strtok(NULL, " "));

    switch(c.command){
      case forward:
        xPos += c.arg;
        break;
      case up:
        yPos += c.arg;
        break;
      case down:
        yPos -= c.arg;
        break;
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