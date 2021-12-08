#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT "input.text"
int partOne() {
  char letters[10][10];
  char inputs[4][10];

  int count = 0;
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  while (fscanf(in_file, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s ",
                letters[0], letters[1], letters[2], letters[3], letters[4],
                letters[5], letters[6], letters[7], letters[8], letters[9],
                inputs[0], inputs[1], inputs[2], inputs[3]) == 14) {
    for (i = 0; i < 4; i++) {
      int sizeOfChars = strlen(inputs[i]);
      switch (sizeOfChars) {
        case 2:
          count++;
          break;
        case 3:
          count++;
          break;
        case 4:
          count++;
          break;
        case 7:
          count++;
          break;

        default:
          break;
      }
    }
  }
  return count;
}

int cmpfunc(const void* a, const void* b) { return *(char*)a - *(char*)b; }
int foldSum(int data[4]) {
  int sum = 0;
  sum += (data[0] * 1000);
  sum += (data[1] * 100);
  sum += (data[2] * 10);
  sum += (data[3]);
  return sum;
}

int partTwo() {
  char letters[10][10];
  char inputs[4][10];
  char sSD[7];
  int answerArr[4];
  int indexes[10];
  int sum = 0;
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  while (fscanf(in_file, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s",
                letters[0], letters[1], letters[2], letters[3], letters[4],
                letters[5], letters[6], letters[7], letters[8], letters[9],
                inputs[0], inputs[1], inputs[2], inputs[3]) == 14) {
    /* Sorting Strings */
    for (i = 0; i < 10; i++) {
      qsort(letters[i], strlen(letters[i]), sizeof(char), cmpfunc);
      switch (strlen(letters[i])) {
        case 2:
          indexes[1] = i;
          break;
        case 3:
          indexes[7] = i;
          break;
        case 4:
          indexes[4] = i;
          break;
        case 7:
          indexes[8] = i;
          break;

        default:
          break;
      }
    }
    for (i = 0; i < 4; i++) {
      qsort(inputs[i], strlen(inputs[i]), sizeof(char), cmpfunc);
    }
    /* Find T */
    for (i = 0; i < 3; i++) {
      if (strcmp(&letters[indexes[7]][i], &letters[indexes[1]][i]) != 0) {
        sSD[0] = letters[indexes[7]][i];
        break;
      }
    }
    /*find TR, BR */
    for (i = 0; i < 10; i++) {
      if (strlen(letters[i]) == 6) { /* Is a 6 9 0 */
        int j = 0;
        int firstMatch = 0;
        int secMatch = 0;
        for (j = 0; j < 6; j++) {
          if (letters[i][j] == letters[indexes[1]][0]) {
            firstMatch = 1;
          }
          if (letters[i][j] == letters[indexes[1]][1]) {
            secMatch = 1;
          }
        }
        /* MUTEX CLAUSES */
        if (!firstMatch == 1) {
          indexes[6] = i;
          sSD[2] = letters[indexes[1]][0];
          sSD[5] = letters[indexes[1]][1];
        }
        if (!secMatch == 1) {
          indexes[6] = i;
          sSD[2] = letters[indexes[1]][1];
          sSD[5] = letters[indexes[1]][0];
        }
      }
    }
    for (i = 0; i < 10; i++) {
      if (strlen(letters[i]) == 5) { /* Is a 2 3 5 */
        int j = 0;
        int tR = 0;
        int bR = 0;
        for (j = 0; j < 5; j++) {
          if (letters[i][j] == sSD[2]) {
            tR = 1;
          }
          if (letters[i][j] == sSD[5]) {
            bR = 1;
          }
        }

        if (tR == 0) {
          indexes[5] = i;
        } else if (bR == 0) {
          indexes[2] = i;
        } else {
          indexes[3] = i;
        }
      }
    }

    for (i = 0; i < 10; i++) {
      if (strlen(letters[i]) == 6) { /* Is a 6 9 0 */
        int j = 0;
        int count = 0;
        if (strcmp(letters[i], letters[indexes[6]]) == 0) {
          continue;
        }

        for (j = 0; j < 8; j++) {
          int k;
          for (k = 0; k < 5; k++) {
            if (letters[indexes[3]][k] == letters[i][j]) {
              count++;
            }
          }
        }

        if (count == 5) {
          indexes[9] = i;
        } else {
          indexes[0] = i;
        }
      }
    }
    /* Loaded up the numbers... Finally */
    for (i = 0; i < 4; i++) {
      int letInd;
      int j;
      for (j = 0; j < 10; j++) {
        if (strcmp(inputs[i], letters[j]) == 0) {
          letInd = j;
          break;
        }
      }

      for (j = 0; j < 10; j++) {
        if (indexes[j] == letInd) {
          answerArr[i] = j;
        }
      }
    }

    sum += foldSum(answerArr);
  }
  return sum;
}

int main() {
  printf("\n%d", partTwo());
  return EXIT_SUCCESS;
}