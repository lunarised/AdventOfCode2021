#include <stdio.h>
#include <stdlib.h>

int partOne() {
  char line[100];
  int ups = 0;
  FILE *in_file = fopen("input.text", "r");
  int previousNumber;
  int currentNumber;
  fgets(line, 100, in_file);
  previousNumber = atoi(line);

  while (fgets(line, 100, in_file) != NULL) {
    currentNumber = atoi(line);
    if (previousNumber < currentNumber) {
      ups++;
    }
    previousNumber = currentNumber;
  }
  return ups;
}
int partTwo() {
  int window[3] = {0, 0, 0};
  int count = 0;
  char line[100];
  int ups = 0;
  int previousNumber;
  int currentNumber;
  FILE *in_file = fopen("input.text", "r");

  fgets(line, 100, in_file);
  window[0] = atoi(line);
  fgets(line, 100, in_file);
  window[1] = atoi(line);
  fgets(line, 100, in_file);
  window[2] = atoi(line);
  previousNumber = window[0] + window[1] + window[2];

  while (fgets(line, 100, in_file) != NULL) {
    window[count % 3] = atoi(line);
    count++;
    currentNumber = window[0] + window[1] + window[2];
    if (previousNumber < currentNumber) {
      ups++;
    }
    previousNumber = currentNumber;
  }
  return ups;
}

int main() {
  printf("%d\n", partOne());
  printf("%d\n", partTwo());
  return EXIT_SUCCESS;
}