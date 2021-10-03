#include <stdio.h>
#include <string.h>
#include <math.h>

int get_bit_id(int n, int bit_index)
{
    return (n & (int)(pow(2, bit_index))) >> bit_index;
}

int main(void)
{
    char MESSAGE[101];
    scanf("%[^\n]", MESSAGE);

    int bit_id;
    for (int i = 0; i < strlen(MESSAGE); ++i)
    {
        int bit_index = 7;
        while (bit_index)
        {
            bit_id = get_bit_id(MESSAGE[i], bit_index - 1);
            if (bit_id == 1)
                printf("0 ");
            else if (bit_id == 0)
                printf("00 ");

            while (get_bit_id(MESSAGE[i], bit_index - 1) == bit_id)
            {
                printf("0");
                bit_index--;
                if (bit_index == 0)
                {
                    if (i + 1 == strlen(MESSAGE))
                        break;
                    ++i;
                    bit_index = 7;
                }
            }
            if (i < strlen(MESSAGE) && bit_index > 0)
                printf(" ");
        }
    }
    printf("\n");

    return (0);
}