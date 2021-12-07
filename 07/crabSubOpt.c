#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT "input.text"
#define nCRABS 1000

int burner(int n) {
  return ((pow(n, 2) + n)/2);
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int partOne() {
  char input[5000];
  int crabX[nCRABS];
  int median = 0;
  char* token;
  int i = 0;
  int totalEnergy = 0;
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
  qsort(crabX, nCRABS, sizeof(int), comp);
  median = (crabX[(nCRABS - 1) / 2] + crabX[nCRABS / 2]) / 2;
   for (int i = 0; i<nCRABS; i++ ){
        totalEnergy += abs(median - crabX[i]);
    }
  return totalEnergy;
}



int partTwo() {
  char input[5000];
  int crabX[nCRABS];
  int totalDistance = 0;
  int totalEnergy = 0;
  int maxN = 0;
  char* token;
  double meanDist;
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
    totalDistance += tokenNum;
    if (tokenNum > maxN) {
      maxN = tokenNum;
    }
    i++;
    token = strtok(NULL, ",");
  }
  meanDist = (totalDistance / nCRABS);

  for (i = 0; i < nCRABS; i++) {
    totalEnergy += burner(abs( meanDist - crabX[i]));
  }
  return totalEnergy;
}

int main() {
  printf("%d\n", partOne());
  printf("%d\n", partTwo()); 
  return EXIT_SUCCESS;
}