#include <./06/BigInt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "input.text"
#define nSTEPS1 80
#define nSTEPS2 256

int fishCount(int fish[9]) {
  int count = 0;
  int i = 0;
  for (i = 0; i < 9; i++) {
    count += fish[i];
  }
  return count;
}

int partOne() {
  char input[1000];
  char* token;
  int states[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(input, 1000, in_file);
  token = strtok(input, ",");
  while (token != NULL) {
    int fish = atoi(token);
    states[fish] += 1;
    token = strtok(NULL, ",");
  }
  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", states[0], states[1],
         states[2], states[3], states[4], states[5], states[6], states[7],
         states[8]);
  for (i = 0; i < nSTEPS1; i++) {
    int j = 0;
    int zeroth = states[0];
    for (j = 0; j < 8; j++) {
      states[j] = states[j + 1];
    }
    states[6] += zeroth;
    states[8] = zeroth;

    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", states[0], states[1],
           states[2], states[3], states[4], states[5], states[6], states[7],
           states[8]);
  }
  return fishCount(states);
}

int partTwo() {
  char input[1000];
  BigInt* sum = BigInt_construct(0);
  char* token;
  BigInt* states[9] = {
      BigInt_construct(0), BigInt_construct(0), BigInt_construct(0),
      BigInt_construct(0), BigInt_construct(0), BigInt_construct(0),
      BigInt_construct(0), BigInt_construct(0), BigInt_construct(0)};
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(input, 1000, in_file);
  token = strtok(input, ",");
  while (token != NULL) {
    int fish = atoi(token);
    states[fish] += 1;
    token = strtok(NULL, ",");
  }
  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", states[0], states[1],
         states[2], states[3], states[4], states[5], states[6], states[7],
         states[8]);
  for (i = 0; i < nSTEPS2; i++) {
    int j = 0;
    BigInt* zeroth = states[0];
    for (j = 0; j < 8; j++) {
      states[j] = states[j + 1];
    }
    BigInt_add(states[6], zeroth);
    states[8] = zeroth;
  }

  for (i = 0; i < 9; i++) {
    BigInt_add(sum, states[i]);
  }
  BigInt_print(sum);
  return EXIT_SUCCESS;
}

int main() {
  printf("%d", partOne());
  partTwo();
  return EXIT_SUCCESS;
}