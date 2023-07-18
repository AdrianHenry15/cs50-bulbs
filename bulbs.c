#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO: ask user for message
    char message[1000];
    printf("Message: ");
    scanf("%s", &message);

    // TODO: make a probram that converts the given string into a series of 8-bit binary numbers, 1 for each character of the string

    // a run through of each character in the message given by user
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // to convert each letter in message into an ASCII value we need to declare each character as an integer or a decimal
        int decimal = message[i];

        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        //convert ASCII value into binary value
        int j = 0;

        while (decimal > 0)
        {
            binary[j] = decimal % 2;
            decimal = decimal / 2;
            j++;
        }

        // this for loop is unique because it starts from k being 7 and iterates down the array for the purpose of having the binary code in the correct order
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    // 0 = off
    if (bit == 0)
    {
        // Dark emoji
        // printf("\U000026AB");
        printf("0");
    }
    // 1 = on
    else if (bit == 1)
    {
        // Light emoji
        // printf("\U0001F7E1");
        printf("1");
    }
}