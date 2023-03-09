#include "tui_utils.h"
#include "string.h"
#include "hal.h"

void clearTUI(void)
{
    static string128 output;
    strinit("", &output);
    for(int i = ASCIIHEIGHT; i>0; --i){
        straddChar(&output,'\n');
        straddChar(&output,'\r');
    }
    sendString(&output);
}

void asciiToString(string128 asciiCon[ASCIIHEIGHT], string128 buffer[ASCIIHEIGHT], const char *asciiArt) {
	for(int h = 0; h < ASCIIHEIGHT; h++) {
		for(int w = 0; w < ASCIIWIDTH; w++) {
			asciiCon[h].content[w] = asciiArt[h * ASCIIWIDTH + w];
			buffer[h].content[w] = '\0';
		}
		straddChar(&asciiCon[h], '\n');
		straddChar(&asciiCon[h], '\r');
		asciiCon[h].length = 40;
		buffer[h].length = 0;
	}
}

void expandAsciArt(const string128 asciiCon[ASCIIHEIGHT], string128 buffer[ASCIIHEIGHT], int p) {
	for (int i = 0; i < p; i++) {
		sendString(&asciiCon[i]);
		sleep(1);
	};
}

int power(int base, int exp)
{
    if (exp < 0)
    {
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

int getDigiCount(int n)
{
    int dc = 0;
    do
    {
        n = n / 10;
        dc++;
    } while (n != 0);
    return dc;
}

int stringDigitsToInt(const string128 *s)
{
    int num = 0;
    int length = s->length - 1;
    int i = 0;

    while (length >= 0)
    {
        num += charDigitToInt(s->content[i]) * power(10, length);
        i++;
        length--;
    }

    return num;
}

// TODO: after 9 the digits are printed in wrong order 13 => 31
void intToString(int n, string128 *s)
{
    int temp = 0;
    int len = getDigiCount(n);

    do
    {
        temp = n % 10;
        straddChar(s, temp + ASCII_NUM_DIS);
        //s->content[len - 1] = temp + 48;

        n = n / 10;
        --len;
    } while (len != 0);
}
