#include <stdio.h>
#include <string.h>

int countIncreasesInSlidingData(int *counter, int *inputArray, int noOfItems)
{
    int previous_sum = inputArray[0] + inputArray[1] + inputArray[2];
    for (int i=1; i < noOfItems - 2; i++)
    {
        int current_sum = inputArray[i] + inputArray[i+1] + inputArray[i+2];
        if (current_sum > previous_sum)
        {
            *counter = *counter + 1;
        }
        previous_sum = current_sum;
    }
    return 0;
}

