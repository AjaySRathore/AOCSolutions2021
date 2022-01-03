#include <stdio.h>
#include <math.h>

int binary_to_decimal(int *binaryArray)
{
    int dec;
    int pos = 0;
    for(int i=sizeof(binaryArray)-1; i>=0; i++)
    {
        dec += (pow(2, pos)*(binaryArray[i]));
        pos++;
    }
    return dec;
}

int getPowerConsumption(int *DecoderArray, int count)
{
    int gamma[12];
    int epsilon[12];
    int mid = count/2;
    for(int i=0; i<12; i++)
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
    printf("%d %d", gamma[1], epsilon[1]);
    int gammaRate, epsilonRate;
    gammaRate = binary_to_decimal(gamma);
    printf("gammaRate %d", gammaRate);
    return 0;
}


int main()
{
    int gammaDecoderArray[12] = {0};
    const char fpath[] = "/home/ajay/c_projects/inputDay3.txt";
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
    return 0;
}
