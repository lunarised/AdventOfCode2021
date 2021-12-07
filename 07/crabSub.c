#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT "input.text"
#define nCRABS 1000
int partOne() {
  char input[5000];
  int crabX[nCRABS];
  char* token;
  int i = 0;
  int smallestSum = INT_MAX;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(input, 5000, in_file);
  token = strtok(input, ",");
  while (token != NULL) {
    crabX[i] = atoi(token);
    i++;
    token = strtok(NULL, ",");
  }
  for (i = 0; i < nCRABS; i++) {
    int j = 0;
    int sum = 0;
    for (j = 0; j < nCRABS; j++) {
      sum += abs(crabX[j] - crabX[i]);
    }
    if (sum < smallestSum) {
      smallestSum = sum;
    }
  }
  return smallestSum;
}

int burner(int distance) {
  int i = 0;
  int sum = 0;
  for (i = 1; i <= distance; i++) {
    sum += i;
  }
  return sum;
}

int partTwo() {
  char input[5000];
  int crabX[nCRABS];
  int maxN = 0;
  char* token;
  int i = 0;
  int smallestSum = INT_MAX;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(input, 5000, in_file);
  token = strtok(input, ",");
  while (token != NULL) {
    int tokenNum = atoi(token);
    crabX[i] = tokenNum;
    if (tokenNum > maxN) {
      maxN = tokenNum;
    }
    i++;
    token = strtok(NULL, ",");
  }
  for (i = 0; i < maxN; i++) {
    int j = 0;
    int sum = 0;
    for (j = 0; j < nCRABS; j++) {
      sum += burner(abs(crabX[j] - i));
      if (sum > smallestSum) {
        break;
      }
    }
    if (sum < smallestSum) {
      smallestSum = sum;
    }
  }
  return smallestSum;
}

int main() {
  printf("%d", partOne());
  printf("%d", partTwo());
  return EXIT_SUCCESS;
}