#include "tui_utils.h"

const int ASCII_NUM_DIS = 48;

void clearTUI(void){

}

int charDigitToInt(const char c)
{
    return c - ASCII_NUM_DIS;
}

int stringDigitsToInt(const char * s, int len)
{
    int num = 0;
    --len;

    for(int i = 0; len >= 0; --len){
        num += charDigitToInt(s[i]) * power(10, len);
    }

    return num;
}

char *intToText(int n, char * ca){
    int temp = 0;
    int len = getDigiCount(n);

    do{
        temp = n%10;
        ca[len-1] = temp + 48;

        n = n/10;
        --len;
    }while(len != 0);

    return ca;
}

int getDigiCount(int n){
    int dc = 0;
    do{
        n = n/10;
        dc++;
    }while(n != 0);
    return dc;
}

int power(int base, int exp)
{
    if(exp < 0)
    return -1;

    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}