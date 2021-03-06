#include <stdio.h>
#include <string.h>
int countIncreasesInSlidingData(int *counter, int *inputArray, int noOfItems);
int * getInput(int *integers, char filepath[]);

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
    printf("Submit the program to run\n");
    printf("\t1. Normal Increases\n");
    printf("\t2. Sliding Incrases\n");
    printf("\t3. Position Dectector\n");
    int program;
    scanf("%d", &program);
    printf("Running progam no. %d", program);
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
    char commands[noOfScans];
    static int increasesCount = 0;
    static int multiplicationResult;
    int result = -1;
    switch (program)
    {
        case 1:

            inputArray = getInput(integers, filepath);
            result = countIncreasesInData(&increasesCount, inputArray, noOfScans);
            printf("Increases count: %d status: %d", increasesCount, result);
            break;
        case 2:
            inputArray = getInput(integers, filepath);
            result = countIncreasesInSlidingData(&increasesCount, inputArray, noOfScans);
            printf("Increases count: %d status: %d", increasesCount, result);
            break;
        case 3:
            getPositionInput(&integers, &commands, filepath);
            printf("%d %c", integers[0], commands[0]);
            multiplicationResult = positionDetecter(&integers, &commands, noOfScans);
            printf("Mulitplication Result: %d \n", multiplicationResult);
        default:
            result = -1;
    }


    return 0;
}

