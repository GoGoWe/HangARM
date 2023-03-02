#include "tui_utils.h"
#include "string.h"

const int ASCII_NUM_DIS = 48;

void clearTUI(void) {

}

int power(int base, int exp)
{
    if(exp < 0) {
        return -1;
    }

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

int charDigitToInt(const char c)
{
    return c - ASCII_NUM_DIS;
}

int getDigiCount(int n) {
    int dc = 0;
    do {
        n = n/10;
        dc++;
    } while(n != 0);
    return dc;
}

int stringDigitsToInt(const string128 *s)
{
    int num = 0;
    int length = s->length - 1;
    int i = 0;

    while(length >= 0) {
        num += charDigitToInt(s->content[i]) * power(10, length);
        i++;
        length--;
    }

    return num;
}

void intToString(int n, string128 *s) {
    int temp = 0;
    int len = getDigiCount(n);

    do {
        temp = n%10;
        s->content[len-1] = temp + 48;

        n = n/10;
        --len;
    } while(len != 0);
}

