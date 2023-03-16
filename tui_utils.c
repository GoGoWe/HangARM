#include "tui_utils.h"
#include "string.h"
#include "hal.h"

void clearTUI(void)
{
    static string128 output;

    for(int i = TUIHIGHT; i>0; --i){
        straddChar(&output,'\n');
        straddChar(&output,'\r');
    }
    sendString(&output);
}

// TODO: Change this this way you can print more than one ASCII Art
//       Additionally the asciiContainer can not be cleared make this
//       the same way as the String126 struct so that it can be created
//       with different sizes and reinisilized when the game starts over
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

//                                                            2
void expandAsciArt(const string128 asciiCon[ASCIIHEIGHT], int p) {
	for (int i = p; i >= 0; i--) {


		sendString(&asciiCon[ASCIIHEIGHT - i]);
		//sleep(1);
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

int getDigitsCount(int n)
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

void intToString(int n, string128 *s)
{
    strclear(s);

    int temp = 0;
    int len = getDigitsCount(n);
    s->length = len;
    
    do
    {
        temp = n % 10;
        s->content[len - 1] = temp + 48;

        n = n / 10;
        --len;
    } while (len != 0);
}
