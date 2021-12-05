#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nBALLS 100
#define BOARDSIZE 5
#define nSQUARES 100
#define INPUT "input.text"

struct Box {
  int value;
  int isHit;
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
      b.isHit = 0;
      sq.Box[line][col] = b;

      token = strtok(NULL, " ");
      col++;
    }
  }
  return sq;
}

int checkForWin(struct Square sq, int row, int col) {
  int rowPass = 1;
  int colPass = 1;
  int colI;
  int rowI;
  /* Check Row */
  for (colI = 0; colI < BOARDSIZE; colI++) {
    if (sq.Box[row][colI].isHit == 0) {
      rowPass = 0;
    }
  }
  for (rowI = 0; rowI < BOARDSIZE; rowI++) {
    if (sq.Box[rowI][col].isHit == 0) {
      colPass = 0;
    }
  }
  if (rowPass == 1 || colPass == 1) {
    return 1;
  }
  return 0;
}
int squareValue(struct Square sq) {
  int sum = 0;
  int rowI = 0;
  int colI = 0;
  for (rowI = 0; rowI < BOARDSIZE; rowI++) {
    for (colI = 0; colI < BOARDSIZE; colI++) {
      if (sq.Box[rowI][colI].isHit == 0) {
        sum += sq.Box[rowI][colI].value;
      }
    }
  }
  return sum;
}

int partOne() {
  int hasBoardWon = 0;
  char inputString[nBALLS * 3];
  int winningSquare = 0;
  int winningNumber = 0;
  int i;
  int* values;
  int nBallDrawn;
  struct Square squares[nSQUARES];

  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  fgets(inputString, nBALLS * 3, in_file);
  values = loadBalls(inputString);
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

  for (nBallDrawn = 0; nBallDrawn < nBALLS; nBallDrawn++) {
    int squareChecked = 0;
    if (hasBoardWon != 1) {
      for (squareChecked = 0; squareChecked < nSQUARES; squareChecked++) {
        int row = 0;
        for (row = 0; row < BOARDSIZE; row++) {
          int col = 0;
          for (col = 0; col < BOARDSIZE; col++) {
            if (squares[squareChecked].Box[row][col].value ==
                values[nBallDrawn]) {
              squares[squareChecked].Box[row][col].isHit = 1;
              hasBoardWon = checkForWin(squares[squareChecked], row, col);
              if (hasBoardWon == 1) {
                winningNumber = values[nBallDrawn];
                winningSquare = squareChecked;
                return winningNumber * squareValue(squares[winningSquare]);
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  printf("%d\n", partOne());

  return EXIT_SUCCESS;
}