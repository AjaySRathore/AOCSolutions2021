#include <stdio.h>
#include <math.h>

#define INPUT_SIZE 12

int binary_to_decimal(int *binaryArray)
{
    int dec = 0;
    int pos = 0;
    for(int i=INPUT_SIZE - 1; i>=0; i--)
    {
        dec += (pow(2, pos)*(binaryArray[i]));
        printf("\n array: %d pos: %d", binaryArray[i], i);
        pos++;
    }
    return dec;
}

int getPowerConsumption(int *DecoderArray, int count)
{
    int gamma[INPUT_SIZE];
    int epsilon[INPUT_SIZE];
    int mid = count/2;
    for(int i=0; i<INPUT_SIZE; i++)
    {
        if(DecoderArray[i] < mid)
        {
            gamma[i] = 0;
            epsilon[i] = 1;
        }
        else
        {
            gamma[i] = 1;
            epsilon[i] = 0;
        }
    }
    printf("\nGamma:");
    for (int i=0; i<INPUT_SIZE; i++)
        printf("%d", gamma[i]);
    printf("\n");
    printf("\nEpsilon:");
    for (int i=0; i<INPUT_SIZE; i++)
        printf("%d", epsilon[i]);
    printf("\n");
    int gammaRate, epsilonRate;
    gammaRate = binary_to_decimal(gamma);
    epsilonRate = binary_to_decimal(epsilon);
    printf("\ngammaRate %d %d\n", gammaRate, epsilonRate);
    return gammaRate * epsilonRate;
}


int main()
{
    int gammaDecoderArray[INPUT_SIZE] = {0};
    const char fpath[] = "C:\\Users\\Ajay\\Desktop\\aocinputs\\inputDay3.txt";
    char c;
    int i = 0;
    int count = 1;
    FILE *file = fopen(fpath, "r");
    c = getc(file);
    while (c!=EOF)
    {
        switch (c)
        {
            case '1':
                gammaDecoderArray[i] += 1;
                i++;
                break;
            case '0':
                i++;
                break;
            case '\n':
                i = 0;
                count++;
                break;
            default:
                break;
        }
        c = getc(file);

    }
    fclose(file);
    int result;
    result = getPowerConsumption(gammaDecoderArray, count);
    printf("\nresult: %d\n", result);
    return 0;
}
