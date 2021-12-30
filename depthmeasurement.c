#include <stdio.h>
#include <string.h>

int * getInput(int *integers, char filepath[])
{

    FILE *file = fopen(filepath, "r");
    int i=0;
    int num;
    while(fscanf(file, "%d", &num) > 0)
    {
        integers[i] = num;
        i++;
    }
    fclose(file);
    return integers;
}

int countIncreasesInData(int *counter, int *inputArray, int noOfItems)
{
    int previous = inputArray[0];
    for (int i=1; i < noOfItems; i++)
    {
        if (inputArray[i] > previous)
        {
            *counter = *counter + 1;
        }
        previous = inputArray[i];
    }
    return 0;
}

int main()
{
    int *inputArray;
    char filepath[FILENAME_MAX];
    printf("Submit input file path:");
    scanf("%s", &filepath);
    FILE *file = fopen(filepath, "r");
    int noOfScans = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
    {
        if (c == '\n')
            noOfScans = noOfScans + 1;
    }
    fclose(file);
    int integers[noOfScans];
    inputArray = getInput(integers, filepath);
    static int increasesCount = 0;
    int result = countIncreasesInData(&increasesCount, inputArray, noOfScans);
    printf("Increases count: %d", increasesCount);
    return 0;
}

