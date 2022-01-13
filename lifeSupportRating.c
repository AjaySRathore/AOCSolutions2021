#include <stdio.h>
#include <math.h>
#include <string.h>
#define NO_OF_INPUT 1000
#define INPUT_SIZE 12
void applyOxygenFilter(char totalInputArrayOxygen[NO_OF_INPUT][INPUT_SIZE+1], int i, char key);

int binary_to_decimal(int *binaryArray)
{
    int dec = 0;
    int pos = 0;
    for(int i=INPUT_SIZE - 1; i>=0; i--)
    {
        dec += (pow(2, pos)*(binaryArray[i]));
        //printf("\n array: %d pos: %d", binaryArray[i], i);
        pos++;
    }
    return dec;
}

char getDecodingKey(char totalInputArrayOxygen[NO_OF_INPUT][INPUT_SIZE+1], int key_pos)
{
    int score = 0;
    int count = 0;

    for(int i=0; i<NO_OF_INPUT; i++)
    {
        if(totalInputArrayOxygen[i][0] != '\0'){
         if (totalInputArrayOxygen[i][key_pos] == '1'){
            score += 1;
        }
            count++;
        }
    }

    if (count == 1)
        return '2';

    char result = '0';
    int mid = 0;
    if (count & 1)
        mid = (count/2) + 1;
    else
        mid = count/2;

    if (count == 1 && score == 1){
        result = '1';
    }
    else if (score >= mid)
        // 1 implies 1 is most common
        result = '1';
   // printf("\n result: %c, score = %d, mid = %d, count = %d \n", result, score, mid, count);
    return result;
}


int main()
{
    int inputArray[INPUT_SIZE] = {0};
    const char fpath[] = "C:\\Users\\Ajay\\Desktop\\aocinputs\\inputDay3.txt";
    int i = 0;
    int count = NO_OF_INPUT;
    char totalInputArrayOxygen[count][INPUT_SIZE+1];
    char totalInputArrayCarbon[count][INPUT_SIZE+1];
    char input[INPUT_SIZE+1];

    FILE *file = fopen(fpath, "r");
    while(fscanf(file, " %s", input) > 0)
    {
        input[INPUT_SIZE] = '\0';
        strcpy(totalInputArrayOxygen[i], input);
        strcpy(totalInputArrayCarbon[i], input);
        //printf("\n %s : %s ", totalInputArrayOxygen[i], totalInputArrayCarbon[i]);
        i++;
    }
    fclose(file);

    char key;
    //printf("string %p\n", &totalInputArrayOxygen[0]);
    //printf("Carbon %p\n", &totalInputArrayCarbon[0]);

    for (int y=0; y<INPUT_SIZE; y++){
        key = getDecodingKey(totalInputArrayOxygen, y);
        if (key == '2')
            break;
        applyOxygenFilter(totalInputArrayOxygen, y, key);
        //printf("\n ===== oxygen ====== \n");
    }

    for (int i=0; i<INPUT_SIZE; i++){
        key = getDecodingKey(totalInputArrayCarbon, i);
        if (key == '1') {
            applyOxygenFilter(totalInputArrayCarbon, i , '0');
        } else if (key == '0') {
            applyOxygenFilter(totalInputArrayCarbon, i , '1');
        } else {
            break;
        }
        //printf("\n ++++++ carbon ++++++ \n");
    }

    int carbonPos;
    for(int i=0; i<NO_OF_INPUT; i++){
        if (totalInputArrayCarbon[i][0] != '\0') {
            carbonPos = i;
            break;
        }
    }


    int oxygenPos;
    for(int i=0; i<NO_OF_INPUT; i++){
        if (totalInputArrayOxygen[i][0] != '\0') {
            oxygenPos = i;
            break;
        }
    }

    //printf("\n Oxygen: %s", totalInputArrayOxygen[oxygenPos]);
    //printf("\n Carbon: %s", totalInputArrayCarbon[carbonPos]);

    int oxygenRateInteger[INPUT_SIZE] = {0};
    for (int i=0; i<INPUT_SIZE; i++){
        if (totalInputArrayOxygen[oxygenPos][i] == '1')
            oxygenRateInteger[i] = 1;
    }

    int carbonRateInteger[INPUT_SIZE] = {0};
    for (int i=0; i<INPUT_SIZE; i++){
        if (totalInputArrayCarbon[carbonPos][i] == '1')
            carbonRateInteger[i] = 1;
    }

    int lifesupportrating = binary_to_decimal(oxygenRateInteger) * binary_to_decimal(carbonRateInteger);
    printf("\n LifesupportRating %d \n", lifesupportrating);

    return 0;
}

void applyOxygenFilter(char totalInputArray[NO_OF_INPUT][INPUT_SIZE+1], int pos, char charkey){
    //printf("Starting checking %c at pos %d \n", totalInputArray[0][pos], pos);
    for (int x=0; x<NO_OF_INPUT; x++){
        if (totalInputArray[x][0] != '\0' && totalInputArray[x][pos] == charkey) {
                //printf("\n Matching %s for key %c \n", totalInputArray[x], charkey);
                continue;
        }
        else {
            //printf("\n Nulling %c for key %c\n", totalInputArray[x][pos], charkey);
            totalInputArray[x][0] = '\0';
        }
    }
}
