#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT "input.text"
struct Stack {
  char top;
  unsigned capacity;
  char* array;
};

struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char*)malloc(stack->capacity * sizeof(char));
  return stack;
}

int isFull(struct Stack* stack) { return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, char item) {
  if (isFull(stack)) return;
  stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
  if (isEmpty(stack)) return -1;
  return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
  if (isEmpty(stack)) return -1;
  return stack->array[stack->top];
}

int partOne() {
  char line[500];
  int totalValue = 0;
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");

  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  while (fgets(line, 500, in_file) != NULL) {
    int len = (int)strlen(line);
    int value = 0;

    struct Stack* synStack = createStack(500);
    for (i = 0; i < len; i++) {
      if (value != 0) {
        totalValue += value;
        break;
      }
      switch (line[i]) {
        case '{':
          push(synStack, '{');
          break;
        case '(':
          push(synStack, '(');
          break;
        case '<':
          push(synStack, '<');
          break;
        case '[':
          push(synStack, '[');
          break;
        case '}':
          if (peek(synStack) != '{') {
            value += 1197;
          } else {
            pop(synStack);
          }

          break;
        case ')':
          if (peek(synStack) != '(') {
            value += 3;
          } else {
            pop(synStack);
          }
          break;
        case '>':
          if (peek(synStack) != '<') {
            value += 25137;
          } else {
            pop(synStack);
          }
          break;
        case ']':
          if (peek(synStack) != '[') {
            value += 57;
          } else {
            pop(synStack);
          }
          break;
      }
    }
  }
  return totalValue;
}

int comp(const void* elem1, const void* elem2) {
  long long int f = *((long long int*)elem1);
  long long int s = *((long long int*)elem2);
  if (f > s) return 1;
  if (f < s) return -1;
  return 0;
}

long long int partTwo() {
  long long int scores[100];
  int winningLines = 0;
  char line[500];
  int totalValue = 0;
  int i = 0;
  FILE* in_file = fopen(INPUT, "r");

  if (in_file == NULL) {
    printf("File doesnt exist");
  }
  while (fgets(line, 500, in_file) != NULL) {
    int len = (int)strlen(line);
    int fail = 0;

    struct Stack* synStack = createStack(500);
    for (i = 0; i < len; i++) {
      if (fail == 1) {
        break;
      }
      switch (line[i]) {
        case '{':
          push(synStack, '{');
          break;
        case '(':
          push(synStack, '(');
          break;
        case '<':
          push(synStack, '<');
          break;
        case '[':
          push(synStack, '[');
          break;
        case '}':
          if (peek(synStack) != '{') {
            fail = 1;
          } else {
            pop(synStack);
          }

          break;
        case ')':
          if (peek(synStack) != '(') {
            fail = 1;
          } else {
            pop(synStack);
          }
          break;
        case '>':
          if (peek(synStack) != '<') {
            fail = 1;
          } else {
            pop(synStack);
          }
          break;
        case ']':
          if (peek(synStack) != '[') {
            fail = 1;
          } else {
            pop(synStack);
          }
          break;
      }
    }
    if (fail == 0 && peek(synStack) != -1) {
      long long int value = 0;
      while (peek(synStack) != -1) {
        char symbol = pop(synStack);
        switch (symbol) {
          case '\0':
            break;
          case '(':
            value *= 5;
            value += 1;
            break;
          case '[':
            value *= 5;
            value += 2;
            break;
          case '{':
            value *= (long long int)5;
            value += 3;
            break;
          case '<':
            value *= 5;
            value += 4;
            break;
          default:
            break;
        }
      }
      scores[winningLines] = value;
      winningLines++;
    }
  }
  qsort(scores, winningLines, sizeof(long long int), comp);
  return scores[winningLines / 2];
}

int main() {
  printf("%d\n", partOne());
  printf("%lld\n", partTwo());
  return EXIT_SUCCESS;
}