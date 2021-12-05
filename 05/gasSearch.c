#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#include <stdio.h>
#include <stdlib.h>

#define INPUT "input.text"
#define MAPSIZE 1000

struct Point {
  int x;
  int y;
};

int partOne() {
  struct Point src;
  struct Point dest;

  int b[MAPSIZE][MAPSIZE];
  int p;
  int s;
  int i;
  for (s = 0; s < MAPSIZE; s++) {
    for (p = 0; p < MAPSIZE; p++) {
      b[s][p] = 0;
    }
  }

  int count = 0;
  printf("FOO");
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }

  while (fscanf(in_file, "%d,%d -> %d,%d", &src.x, &src.y, &dest.x, &dest.y) ==
         4) {
    printf("%d,%d -> %d,%d", src.x, src.y, dest.x, dest.y);
    if (src.x == dest.x) {
      int yI;
      for (yI = min(src.y, dest.y); yI <= max(src.y, dest.y); yI++) {
        b[src.x][yI] += 1;
      }

    } else if (src.y == dest.y) {
      int xI;
      for (xI = min(src.x, dest.x); xI <= max(src.x, dest.x); xI++) {
        b[xI][src.y] += 1;
      }
    }
  }

  for (s = 0; s < MAPSIZE; s++) {
    for (p = 0; p < MAPSIZE; p++) {
      printf("%d", b[s][p]);
    }
  }
  return count;
}

int main() {
  printf("%d", partOne());
  return EXIT_SUCCESS;
}