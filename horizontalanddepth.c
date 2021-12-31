#include <stdio.h>


int positionDetecter(int *value, char *commands, int noOfCommands)
{
    int horizontalPos = 0, verticalPos = 0;
    for (int i=0; i<noOfCommands; i++)
    {
        switch (*(commands + i))
        {
            case 'f':
                horizontalPos += value[i];
                break;
            case 'u':
                verticalPos -= value[i];
                break;
            case 'd':
                verticalPos += value[i];
                break;
        }
    }
    return (horizontalPos * verticalPos);
}
