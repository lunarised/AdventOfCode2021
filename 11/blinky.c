#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxY 10
#define maxX 10
#define INPUT "./input.text"
#define nSTEPS 100

struct Octopus{
  int value;
  int isFlashing;
};
int partOne() {
  char line[500];
  struct Octopus dumboOctopuses[maxY][maxX];
  int i = 0;
  int j = 0;
  int step = 0;
  int flashes = 0;
  struct Octopus o;
  FILE* in_file = fopen(INPUT, "r");

  if (in_file == NULL) {
    printf("File doesnt exist\n");
    return 1;
  }
  while (fgets(line, 500, in_file) != NULL) {
    for (i = 0; i < maxX; i++) {
      o.value = line[i] - '0';
      o.isFlashing = 0;
      dumboOctopuses[j][i] = o;
    } 
    j++;
  } 


  for (step = 0; step < nSTEPS; step++) {
    int flashing = 0;
    int i;
    int j;
    for ( i = 0; i < maxY; i++) {
      for ( j = 0; j < maxX; j++) {
        dumboOctopuses[j][i].value += 1;
          dumboOctopuses[j][i].isFlashing = 0;
        if (dumboOctopuses[j][i].value > 9){
          flashing = 1;

      }
    }
  }
  
while (flashing){
flashing = 0;

    for ( i = 0; i < maxY; i++) {
      for ( j = 0; j < maxX; j++) {
        if (dumboOctopuses[j][i].value > 9) {
          dumboOctopuses[j][i].value = 0;
          dumboOctopuses[j][i].isFlashing = 1;
          flashes++;
          flashing = 1;
          if (i > 0) { 
            if (dumboOctopuses[j][i - 1].isFlashing == 0) {
              dumboOctopuses[j][i - 1].value++;
            }

            if (j > 0) {
              if (dumboOctopuses[j - 1][i - 1].isFlashing == 0) {
                dumboOctopuses[j - 1][i - 1].value++;
              }

            }
            if (j < maxX - 1) { 
              if (dumboOctopuses[j + 1][i - 1].isFlashing == 0) {
                dumboOctopuses[j + 1][i - 1].value++;
              }

            }
          } 

          if (i < maxY - 1) {
            if (dumboOctopuses[j][i + 1].isFlashing == 0) {
              dumboOctopuses[j][i + 1].value++;
            }

            if (j > 0) {
              if (dumboOctopuses[j - 1][i + 1].isFlashing == 0) {
                dumboOctopuses[j - 1][i + 1].value++;
              }

            }
            if (j < maxX - 1) { 
              if (dumboOctopuses[j + 1][i + 1].isFlashing == 0) {
                dumboOctopuses[j + 1][i + 1].value++;
              }

            }
          } 

          if (j < maxX - 1) {
            if (dumboOctopuses[j + 1][i].isFlashing == 0) {
              dumboOctopuses[j + 1][i].value++;
            }

          }

          if (j > 0) {
            if (dumboOctopuses[j - 1][i].isFlashing == 0) {
              dumboOctopuses[j - 1][i].value++;
            }

          }
        }
        
      }
    }
  }
   } 
  
  
  return flashes;
}


int partTwo() {
  char line[500];
  struct Octopus dumboOctopuses[maxY][maxX];
  int i = 0;
  int j = 0;
  int stepsToFlash = 0;
  int syncFlash = 0;
  struct Octopus o;
  FILE* in_file = fopen(INPUT, "r");

  if (in_file == NULL) {
    printf("File doesnt exist\n");
    return 1;
  }
  while (fgets(line, 500, in_file) != NULL) {
    for (i = 0; i < maxX; i++) {
      o.value = line[i] - '0';
      o.isFlashing = 0;
      dumboOctopuses[j][i] = o;
    } 
    j++;
  } 


  while (syncFlash == 0) {
    int flashing = 0;
    int i;
    int j;
    for ( i = 0; i < maxY; i++) {
      for ( j = 0; j < maxX; j++) {
        dumboOctopuses[j][i].value += 1;
          dumboOctopuses[j][i].isFlashing = 0;
        if (dumboOctopuses[j][i].value > 9){
          flashing = 1;

      }
    }
  }
  
while (flashing){
flashing = 0;

    for ( i = 0; i < maxY; i++) {
      for ( j = 0; j < maxX; j++) {
        if (dumboOctopuses[j][i].value > 9) {
          dumboOctopuses[j][i].value = 0;
          dumboOctopuses[j][i].isFlashing = 1;
          flashing = 1;
          if (i > 0) { 
            if (dumboOctopuses[j][i - 1].isFlashing == 0) {
              dumboOctopuses[j][i - 1].value++;
            }

            if (j > 0) {
              if (dumboOctopuses[j - 1][i - 1].isFlashing == 0) {
                dumboOctopuses[j - 1][i - 1].value++;
              }

            }
            if (j < maxX - 1) { 
              if (dumboOctopuses[j + 1][i - 1].isFlashing == 0) {
                dumboOctopuses[j + 1][i - 1].value++;
              }

            }
          } 

          if (i < maxY - 1) {
            if (dumboOctopuses[j][i + 1].isFlashing == 0) {
              dumboOctopuses[j][i + 1].value++;
            }

            if (j > 0) {
              if (dumboOctopuses[j - 1][i + 1].isFlashing == 0) {
                dumboOctopuses[j - 1][i + 1].value++;
              }

            }
            if (j < maxX - 1) { 
              if (dumboOctopuses[j + 1][i + 1].isFlashing == 0) {
                dumboOctopuses[j + 1][i + 1].value++;
              }

            }
          } 

          if (j < maxX - 1) {
            if (dumboOctopuses[j + 1][i].isFlashing == 0) {
              dumboOctopuses[j + 1][i].value++;
            }

          }

          if (j > 0) {
            if (dumboOctopuses[j - 1][i].isFlashing == 0) {
              dumboOctopuses[j - 1][i].value++;
            }

          }
        }
        
      }
    }
  }
  syncFlash = 1;
  for ( i = 0; i < maxY; i++) {
    for ( j = 0; j < maxX; j++) {
      if( dumboOctopuses[i][j].value != 0){
        syncFlash = 0;
      }
    }
  }
  stepsToFlash++;
   } 
  return stepsToFlash;
}



int main() {
  printf("%d\n", partOne());
    printf("%d\n", partTwo());
  return EXIT_SUCCESS;
}