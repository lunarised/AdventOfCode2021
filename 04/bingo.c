#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nBALLS 100
#define BOARDSIZE 5
#define nSQUARES 100
#define INPUT "input.text"

struct Box {
  int value;
  int isChecked;
};
struct Square {
  struct Box Box[BOARDSIZE][BOARDSIZE];
};

int* loadBalls(char* inp) {
  static int values[100];
  int i = 0;
  char* token;
  token = strtok(inp, ",");
  while (token != NULL) {
    values[i] = atoi(token);
    token = strtok(NULL, ",");
    i++;
  }
  return values;
}
struct Square makeSquare(char inputString[BOARDSIZE][20]) {
  struct Square sq;
  int line = 0;
  for (line = 0; line < 5; line++) {
    char* token;
    int col = 0;
    token = strtok(inputString[line], " ");

    while (token != NULL) {
      struct Box b;
      b.value = atoi(token);
      b.isChecked = 0;
      sq.Box[line][col] = b;

      token = strtok(NULL, " ");
      col++;
    }
  }
  return sq;
}

int partOne() {
  char inputString[nBALLS * 3];
  int i;
  struct Square squares[nSQUARES];

  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(inputString, nBALLS * 3, in_file);

  for (i = 0; i < nSQUARES; i++) {
    int j = 0;
    /* clear whitespace */
    char squareString[5][20];

    fgets(inputString, nBALLS * 3, in_file);
    for (j = 0; j < BOARDSIZE; j++) {
      fgets(inputString, nBALLS, in_file);
      strcpy(squareString[j], inputString);
    }

    squares[i] = makeSquare(squareString);
  }
  return squares[nSQUARES - 1].Box[4][4].value;
}

int main() {
  printf("gi");
  printf("%d\n", partOne());

  return EXIT_SUCCESS;
}