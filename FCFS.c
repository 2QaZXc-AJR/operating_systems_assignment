#include <stdio.h>

int main()
{
    int inputArray[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
    int startPosition = 143;
    int totalMovement = 0;
    
    int size = sizeof(inputArray)/sizeof(int);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (startPosition != 0)
        {
            totalMovement += abs(inputArray[i] - startPosition);
            startPosition = inputArray[i];
        }
        else
        {
            startPosition = inputArray[i];
        }
    }
    printf("%d", totalMovement);
}
