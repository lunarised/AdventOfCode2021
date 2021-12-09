#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT "input.text"
#define MAPY 100
#define MAPX 100
int comp(const void* elem1, const void* elem2) {
  int f = *((int*)elem1);
  int s = *((int*)elem2);
  if (f < s) return 1;
  if (f > s) return -1;
  return 0;
}
int floodFill(int x, int y, int map[MAPY][MAPX]) {
  int count = 1;
  if (map[y][x] == 9) {
    return 0;
  }
  map[y][x] = 9;
  if (x > 0) {
    count += floodFill(x - 1, y, map);
  }
  if (x < MAPX - 1) {
    count += floodFill(x + 1, y, map);
  }
  if (y > 0) {
    count += floodFill(x, y - 1, map);
  }
  if (y < MAPY - 1) {
    count += floodFill(x, y + 1, map);
  }
  return count;
}

int partOne() {
  int map[MAPY][MAPX];
  char line[MAPX + 2];
  int i;

  int j;
  int sum = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }

  for (i = 0; i < MAPY; i++) {
    fgets(line, MAPX + 2, in_file);
    for (j = 0; j < MAPX; j++) {
      map[i][j] = line[j] - '0';
    }
  }
  /* Central Area */
  for (i = 1; i < MAPY - 1; i++) {
    for (j = 1; j < MAPX - 1; j++) {
      if (map[i][j] < map[i][j + 1] && map[i][j] < map[i][j - 1] &&
          map[i][j] < map[i - 1][j] && map[i][j] < map[i + 1][j]) {
        sum += (1 + map[i][j]);
      }
    }
  }
  /* Top Side */
  for (i = 1; i < MAPX - 1; i++) {
    if (map[0][i] < map[0][i + 1] && map[0][i] < map[0][i - 1] &&
        map[0][i] < map[1][i]) {
      sum += (1 + map[0][i]);
    }
  }

  /* Bottom Side */
  for (i = 1; i < MAPX - 1; i++) {
    if (map[MAPY - 1][i] < map[MAPY - 1][i + 1] &&
        map[MAPY - 1][i] < map[MAPY - 1][i - 1] &&
        map[MAPY - 1][i] < map[MAPY - 2][i]) {
      sum += (1 + map[MAPY - 1][i]);
    }
  }

  /* Left Side */
  for (i = 1; i < MAPY - 1; i++) {
    if (map[i][0] < map[i + 1][0] && map[i][0] < map[i - 1][0] &&
        map[i][0] < map[i][1]) {
      sum += (1 + map[i][0]);
    }
  }

  /* Right Side */
  for (i = 1; i < MAPY - 1; i++) {
    if (map[i][MAPX - 1] < map[i + 1][MAPX - 1] &&
        map[i][MAPX - 1] < map[i - 1][MAPX - 1] &&
        map[i][MAPX - 1] < map[i][MAPX - 2]) {
      sum += (1 + map[i][MAPX - 1]);
    }
  }

  /* Corners */
  if (map[0][0] < map[0][1] && map[0][0] < map[1][0]) {
    sum += (1 + map[0][0]);
  }

  if (map[MAPY - 1][0] < map[MAPY - 1][1] &&
      map[MAPY - 1][0] < map[MAPY - 2][0]) {
    sum += (1 + map[MAPY - 1][0]);
  }
  if (map[0][MAPX - 1] < map[0][MAPX - 2] &&
      map[0][MAPX - 1] < map[1][MAPX - 1]) {
    sum += (1 + map[0][MAPX - 1]);
  }

  if (map[MAPY - 1][MAPX - 1] < map[MAPY - 1][MAPX - 2] &&
      map[MAPY - 1][MAPX - 1] < map[MAPY - 2][MAPX - 1]) {
    sum += (1 + map[MAPY - 1][MAPX - 1]);
  }
  return sum;
}
struct Point {
  int x;
  int y;
};

int partTwo() {
  int map2[MAPY][MAPX];
  char line[MAPX + 2];
  int i;
  int j;
  int basinSizes[500] = {-2};
  struct Point localMinima[500];
  int nMinima = 0;
  FILE* in_file = fopen(INPUT, "r");
  if (in_file == NULL) {
    printf("File doesnt exist");
  }

  for (i = 0; i < MAPY; i++) {
    fgets(line, MAPX + 2, in_file);
    for (j = 0; j < MAPX; j++) {
      map2[i][j] = line[j] - '0';
    }
  }
  /* Central Area */
  for (i = 1; i < MAPY - 1; i++) {
    for (j = 1; j < MAPX - 1; j++) {
      if (map2[i][j] < map2[i][j + 1] && map2[i][j] < map2[i][j - 1] &&
          map2[i][j] < map2[i - 1][j] && map2[i][j] < map2[i + 1][j]) {
        struct Point p;
        p.x = j;
        p.y = i;
        localMinima[nMinima] = p;
        nMinima++;
      }
    }
  }
  /* Top Side */
  for (i = 1; i < MAPX - 1; i++) {
    if (map2[0][i] < map2[0][i + 1] && map2[0][i] < map2[0][i - 1] &&
        map2[0][i] < map2[1][i]) {
      struct Point p;
      p.x = i;
      p.y = 0;
      localMinima[nMinima] = p;
      nMinima++;
    }
  }

  /* Bottom Side */
  for (i = 1; i < MAPX - 1; i++) {
    if (map2[MAPY - 1][i] < map2[MAPY - 1][i + 1] &&
        map2[MAPY - 1][i] < map2[MAPY - 1][i - 1] &&
        map2[MAPY - 1][i] < map2[MAPY - 2][i]) {
      struct Point p;
      p.x = i;
      p.y = MAPY - 1;
      localMinima[nMinima] = p;
      nMinima++;
    }
  }

  /* Left Side */
  for (i = 1; i < MAPY - 1; i++) {
    if (map2[i][0] < map2[i + 1][0] && map2[i][0] < map2[i - 1][0] &&
        map2[i][0] < map2[i][1]) {
      struct Point p;
      p.x = 0;
      p.y = i;
      localMinima[nMinima] = p;
      nMinima++;
    }
  }

  /* Right Side */
  for (i = 1; i < MAPY - 1; i++) {
    if (map2[i][MAPX - 1] < map2[i + 1][MAPX - 1] &&
        map2[i][MAPX - 1] < map2[i - 1][MAPX - 1] &&
        map2[i][MAPX - 1] < map2[i][MAPX - 2]) {
      struct Point p;
      p.x = MAPX - 1;
      p.y = i;
      localMinima[nMinima] = p;
      nMinima++;
    }
  }

  /* Corners */
  if (map2[0][0] < map2[0][1] && map2[0][0] < map2[1][0]) {
    struct Point p;
    p.x = 0;
    p.y = 0;
    localMinima[nMinima] = p;
    nMinima++;
  }

  if (map2[MAPY - 1][0] < map2[MAPY - 1][1] &&
      map2[MAPY - 1][0] < map2[MAPY - 2][0]) {
    struct Point p;
    p.x = 0;
    p.y = MAPY - 1;
    localMinima[nMinima] = p;
    nMinima++;
  }
  if (map2[0][MAPX - 1] < map2[0][MAPX - 2] &&
      map2[0][MAPX - 1] < map2[1][MAPX - 1]) {
    struct Point p;
    p.x = MAPX - 1;
    p.y = 0;
    localMinima[nMinima] = p;
    nMinima++;
  }

  if (map2[MAPY - 1][MAPX - 1] < map2[MAPY - 1][MAPX - 2] &&
      map2[MAPY - 1][MAPX - 1] < map2[MAPY - 2][MAPX - 1]) {
    struct Point p;
    p.x = MAPX - 1;
    p.y = MAPY - 1;
    localMinima[nMinima] = p;
    nMinima++;
  }
  for (i = 0; i < nMinima; i++) {
    basinSizes[i] = floodFill(localMinima[i].x, localMinima[i].y, map2);
  }
  qsort(basinSizes, nMinima, sizeof(int), comp);
  return ((basinSizes[0] * basinSizes[1]) * basinSizes[2]);
}

int main() {
  printf("%d\n", partOne());
  printf("%d\n", partTwo());
  return EXIT_SUCCESS;
}