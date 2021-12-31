#include <stdio.h>

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

void getPositionInput(int *integers, char *commands, char filepath[])
{

    FILE *file = fopen(filepath, "r");
    int i=0;
    int num;
    char command[20];
    while(fscanf(file, "%s %d", &command, &num) > 0)
    {
        integers[i] = num;
        commands[i] = command[0];
        i++;
    }
    fclose(file);
}
