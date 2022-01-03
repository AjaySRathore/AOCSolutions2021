#include <stdio.h>


int positionDetecter(int *value, char *commands, int noOfCommands)
{
    int horizontalPos = 0, verticalPos = 0, aim = 0;
    for (int i=0; i<noOfCommands; i++)
    {
        switch (*(commands + i))
        {
            case 'f':
                horizontalPos += value[i];
                verticalPos += (aim * value[i]);
                break;
            case 'u':
                aim -= value[i];
                break;
            case 'd':
                aim += value[i];
                break;
        }
    }
    return (horizontalPos * verticalPos);
}
