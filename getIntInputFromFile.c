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
