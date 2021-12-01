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
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }

  while (fscanf(in_file, "%d,%d -> %d,%d", &src.x, &src.y, &dest.x, &dest.y) ==
         4) {
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
    else{
      struct Point diagSrc;
      struct Point diagDest;
      int length;
      int i;
      if (src.x> dest.x){
        printf("%d %d", src.x, dest.x);
        length = src.x - dest.x;
        diagSrc.x = dest.x;
        diagSrc.y = dest.y;
        diagDest.x = src.x;
        diagDest.y = src.y;
      }
      else{
        printf("HIT");
        length = dest.x - src.x;
        diagSrc.x = src.x;
        diagSrc.y = src.y;
        diagDest.x = dest.x;
        diagDest.y = dest.y;
      }

      /* If rising */
      if (diagDest.y < diagSrc.y){
        printf("%d, %d -> %d, %d :: %d\n", src.x, src.y, dest.x, dest.y, length);
        for (i = 0; i <= length; i++){
          printf("%d, %d \n", diagSrc.x+i, diagSrc.y-i);
          b[diagSrc.x+i][diagSrc.y-i] += 1;
        }
      }
      else{
            for (i = 0; i <= length; i++){
          b[diagSrc.x+i][diagSrc.y+i] += 1;
        }    
      }

    }
  }

  for (s = 0; s < MAPSIZE; s++) {
    for (p = 0; p < MAPSIZE; p++) {
      if (b[p][s] > 1) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  printf("%d", partOne());
  return EXIT_SUCCESS;
}