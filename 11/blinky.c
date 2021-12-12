#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxY 5
#define maxX 5
#define INPUT "tiny.text"
#define nSTEPS 1
int partOne() {
  char line[500];
  int dumboOctopuses[maxY][maxX];
  int i = 0;
  int j = 0;
  int step = 0;
  FILE* in_file = fopen(INPUT, "r");

  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  while (fgets(line, 500, in_file) != NULL) {
    for (i = 0; i < maxX; i++) {
      dumboOctopuses[j][i] = line[i] - '0';
    }
    j++;
  }
  for (step = 0; step < nSTEPS; step++) {
    int flashing = 0;
    int i;
    int j;
    for (int i = 0; i < maxY; i++) {
      for (int j = 0; j < maxX; j++) {
        dumboOctopuses[j][i] += 1;
        /*if (dumboOctopuses[j][i] > 9) {
          dumboOctopuses[j][i] = 0;
        } */
      }
    }

    for (int i = 0; i < maxY; i++) {
      for (int j = 0; j < maxX; j++) {
        if (dumboOctopuses[j][i] > 9) {
          dumboOctopuses[j][i] = 0;
          if (i > 0) { /* N */
            if (dumboOctopuses[j][i - 1] != 0) {
              dumboOctopuses[j][i - 1]++;
            }
            if (dumboOctopuses[j][i - 1] > 9) {
              dumboOctopuses[j][i - 1] = 0;
            }
            if (j > 0) { /* NE */
              if (dumboOctopuses[j - 1][i - 1] != 0) {
                dumboOctopuses[j - 1][i - 1]++;
              }
              if (dumboOctopuses[j - 1][i - 1] > 9) {
                dumboOctopuses[j - 1][i - 1] = 0;
              }
            }
            if (j < maxX - 1) { /* NW */
              if (dumboOctopuses[j + 1][i - 1] != 0) {
                dumboOctopuses[j + 1][i - 1]++;
              }
              if (dumboOctopuses[j + 1][i - 1] > 9) {
                dumboOctopuses[j + 1][i - 1] = 0;
              }
            }
          } /* Done Northers */

          if (i < maxY - 1) { /* S */
            if (dumboOctopuses[j][i + 1] != 0) {
              dumboOctopuses[j][i + 1]++;
            }
            if (dumboOctopuses[j][i + 1] > 9) {
              dumboOctopuses[j][i + 1] = 0;
            }
            if (j > 0) { /* SE */
              if (dumboOctopuses[j - 1][i + 1] != 0) {
                dumboOctopuses[j - 1][i + 1]++;
              }
              if (dumboOctopuses[j - 1][i + 1] > 9) {
                dumboOctopuses[j - 1][i + 1] = 0;
              }
            }
            if (j < maxX - 1) { /* SW */
              if (dumboOctopuses[j + 1][i + 1] != 0) {
                dumboOctopuses[j + 1][i + 1]++;
              }
              if (dumboOctopuses[j + 1][i + 1] > 9) {
                dumboOctopuses[j + 1][i + 1] = 0;
              }
            }
          } /* Done southers */

          if (j < maxX - 1) {
            if (dumboOctopuses[j + 1][i] != 0) {
              dumboOctopuses[j + 1][i]++;
            }
            if (dumboOctopuses[j + 1][i] > 9) {
              dumboOctopuses[j + 1][i] = 0;
            }
          }

          if (j > 0) {
            if (dumboOctopuses[j - 1][i] != 0) {
              dumboOctopuses[j - 1][i]++;
            }
            if (dumboOctopuses[j - 1][i] > 9) {
              dumboOctopuses[j - 1][i] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < maxY; i++) {
    for (int j = 0; j < maxX; j++) {
      printf("%d", dumboOctopuses[i][j]);
    }
    printf("\n");
  }
  return 2;
}

int main() {
  printf("%d", partOne());
  return EXIT_SUCCESS;
}