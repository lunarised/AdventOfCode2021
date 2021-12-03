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
  size_t len = strlen(bits);
  for (i = len - 1; i != -1; i--) {
    printf("%c is the character im working on\n", bits[i]);
    if (bits[i] == '1') {
      value += pow(2, power);
      power++;
    }
    if (bits[i] == '0') power++;
  }
  printf("%d\n", value);
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
  printf("%d\n", value);
  return value;
}
/*
int partOne() {
  int bitN;
  int bits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char gammaBits[12];
  char epsilonBits[12];
  char line[100];
  int lineCount = 0;
  FILE* in_file = fopen("input.text", "r");
  while (fgets(line, 100, in_file) != NULL) {
    for (bitN = 0; bitN < 12; bitN++) {
      if (line[bitN] == '1') {
        bits[bitN]++;
      }
    }
    lineCount++;
  }
  for (bitN = 0; bitN < 12; bitN++) {
    printf("%d ", bits[bitN]);
    gammaBits[bitN] = bits[bitN] >= lineCount / 2 ? '1' : '0';
    epsilonBits[bitN] = bits[bitN] > lineCount / 2 ? '0' : '1';
  }

  return (bitsToInt(gammaBits) * bitsToInt(epsilonBits));
}
*/
int MostPopularBits() {
  int parseNumber = 0;
  FILE* in_file;
  char line[100];
  char firstNumber[100];
  int mostPopular[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  /* Go through each digit */
  for (parseNumber = 0; parseNumber < LEN; parseNumber++) {
    int length = 0;
    in_file = fopen(INPUT, "r");
    while (fgets(line, 100, in_file) != NULL) {
      int i = 0;
      int failure = 0;
      for (i = 0; i < parseNumber; i++) {
        if ((line[i] == '1' && mostPopular[i] != 1) ||
            (line[i] == '0' && mostPopular[i] != 0)) {
          failure = 1;
        }
      }
      if (failure == 0) {
        if (length == 0) {
          memcpy(firstNumber, line, 12);
        }
        if (line[parseNumber] == '1') {
          mostPopular[parseNumber]++;
        }
        length++;
      }
    }

    printf("%d on parse %d, length %d soooo ", mostPopular[parseNumber],
           parseNumber, length);
    mostPopular[parseNumber] =
        mostPopular[parseNumber] >= (length - mostPopular[parseNumber]) ? 1 : 0;
    printf("%d\n", mostPopular[parseNumber]);
    if (length == 1) {
      printf("EARLY EXIT");

      return charBitsToInt(firstNumber);
    }
  }

  return numBitsToInt(mostPopular);
}

int LeastPopularBits() {
  int parseNumber = 0;
  FILE* in_file;
  char line[100];
  char firstNumber[100];
  int leastPopular[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  /* Go through each digit */
  for (parseNumber = 0; parseNumber < LEN; parseNumber++) {
    int length = 0;
    in_file = fopen(INPUT, "r");
    while (fgets(line, 100, in_file) != NULL) {
      int i = 0;
      int failure = 0;
      for (i = 0; i < parseNumber; i++) {
        if ((line[i] == '1' && leastPopular[i] != 1) ||
            (line[i] == '0' && leastPopular[i] != 0)) {
          failure = 1;
        }
      }
      if (failure == 0) {
        if (length == 0) {
          memcpy(firstNumber, line, 12);
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
      printf("EARLY EXIT |%s|\n", firstNumber);
      return charBitsToInt(firstNumber);
    }
  }

  return numBitsToInt(leastPopular);
}

int main() {
  /*printf("%d\n", partOne());*/
  printf("%d\n", MostPopularBits() * LeastPopularBits());
  return EXIT_SUCCESS;
}