#include <stdlib.h>
#include <stdio.h>

int partOne()
{
    char line[100];
    int ups = 0;
    FILE *in_file = fopen("input.text", "r");

    fgets(line, 100, in_file);
    int previousNumber = atoi(line);
    int currentNumber;

    while (fgets(line, 100, in_file) != NULL)
    {
        currentNumber = atoi(line);
        if (previousNumber < currentNumber)
        {
            ups++;
        }
        previousNumber = currentNumber;
    }
    return ups;
}

int main()
{
    printf("%d", partOne());
}
