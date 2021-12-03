#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wsizeof-array-argument"
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
#define LEN 12
#define INPUT "input.text"
int charBitsToInt(char bits[]) {
  int i;
  int value = 0;
  int power = 0;
  for (i = LEN - 1; i != -1; i--) {
    if (bits[i] == '1') {
      value += pow(2, power);
      power++;
    }
    if (bits[i] == '0') power++;
  }
  return value;
}

int numBitsToInt(int bits[]) {
  int i;
  int value = 0;
  int power = 0;

  for (i = LEN - 1; i != -1; i--) {
    if (bits[i] == 1) value += pow(2, power);
    power++;
  }
  return value;
}

int partOne() {
  int bitN;
  int bits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char gammaBits[LEN];
  char epsilonBits[LEN];
  char line[LEN];
  int lineCount = 0;
  FILE* in_file = fopen(INPUT, "r");
  while (fgets(line, LEN, in_file) != NULL) {
    for (bitN = 0; bitN < LEN; bitN++) {
      if (line[bitN] == '1') {
        bits[bitN]++;
      }
    }
    lineCount++;
  }
  for (bitN = 0; bitN < LEN; bitN++) {
    gammaBits[bitN] = bits[bitN] >= lineCount / 2 ? '1' : '0';
    epsilonBits[bitN] = bits[bitN] > lineCount / 2 ? '0' : '1';
  }

  return (charBitsToInt(gammaBits) * charBitsToInt(epsilonBits));
}

int MostPopularBits() {
  int parseNumber = 0;
  FILE* in_file;
  char line[100];
  char firstNumber[LEN];
  int mostPopular[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  /* Go through each digit */
  for (parseNumber = 0; parseNumber < LEN; parseNumber++) {
    int length = 0;
    in_file = fopen(INPUT, "r");
    while (fgets(line, 100, in_file) != NULL) {
      int i = 0;
      int failure = 0;
      line[strcspn(line, "\n")] = 0;

      for (i = 0; i < parseNumber; i++) {
        if ((line[i] == '1' && mostPopular[i] != 1) ||
            (line[i] == '0' && mostPopular[i] != 0)) {
          failure = 1;
        }
      }
      if (failure == 0) {
        if (length == 0) {
          memcpy(firstNumber, line, LEN);
        }
        if (line[parseNumber] == '1') {
          mostPopular[parseNumber]++;
        }
        length++;
      }
    }

    mostPopular[parseNumber] =
        mostPopular[parseNumber] >= (length - mostPopular[parseNumber]) ? 1 : 0;

    if (length == 1) {
      return charBitsToInt(firstNumber);
    }
  }

  return numBitsToInt(mostPopular);
}

int LeastPopularBits() {
  int parseNumber = 0;
  FILE* in_file;
  char line[100];
  char firstNumber[LEN];
  int leastPopular[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  /* Go through each digit */
  for (parseNumber = 0; parseNumber < LEN; parseNumber++) {
    int length = 0;
    in_file = fopen(INPUT, "r");
    while (fgets(line, 100, in_file) != NULL) {
      int i = 0;
      int failure = 0;
      line[strcspn(line, "\n")] = 0;
      for (i = 0; i < parseNumber; i++) {
        if ((line[i] == '1' && leastPopular[i] != 1) ||
            (line[i] == '0' && leastPopular[i] != 0)) {
          failure = 1;
        }
      }
      if (failure == 0) {
        if (length == 0) {
          memcpy(firstNumber, line, LEN);
          strtok(firstNumber, "\n");
        }
        if (line[parseNumber] == '0') {
          leastPopular[parseNumber]++;
        }
        length++;
      }
    }

    leastPopular[parseNumber] =
        leastPopular[parseNumber] > (length - leastPopular[parseNumber]) ? 1
                                                                         : 0;

    if (length == 1) {
      return charBitsToInt(firstNumber);
    }
  }

  return numBitsToInt(leastPopular);
}

int main() {
  printf("%d\n", partOne());
  printf("%d\n", MostPopularBits() * LeastPopularBits());
  return EXIT_SUCCESS;
}