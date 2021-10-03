#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void decode(char *message, int start, char rotors[3][28])
{
    for (int i = 0; i < strlen(message); ++i)
    {
        message[i] = 'A' + (int)(strchr(rotors[2], message[i]) - rotors[2]);
        message[i] = 'A' + (int)(strchr(rotors[1], message[i]) - rotors[1]);
        message[i] = 'A' + (int)(strchr(rotors[0], message[i]) - rotors[0]);
        message[i] = (message[i] - 'A') - start - i;
        if (message[i] < 0)
            message[i] = 26 - (abs(message[i]) % 26);
        message[i] += 'A';
        if (message[i] == '[')
            message[i] = 'A';
    }
    printf("%s\n", message);
}

void encode(char message[1025], int start, char rotors[3][28])
{
    for (int i = 0; i < strlen(message); ++i)
    {
        message[i] = 'A' + ((message[i] - 'A' + start + i) % 26);
        message[i] = rotors[0][message[i] - 'A'];
        message[i] = rotors[1][message[i] - 'A'];
        message[i] = rotors[2][message[i] - 'A'];
    }
    printf("%s\n", message);
}

int main(void)
{
    char rotors[3][28];

    char operation[257];
    scanf("%[^\n]", operation);

    int pseudo_random_number;
    scanf("%d", &pseudo_random_number);
    fgetc(stdin);

    for (int i = 0; i < 3; i++)
    {
        char rotor[28];
        scanf("%[^\n]", rotor);
        fgetc(stdin);
        strcpy(rotors[i], rotor);
    }

    char message[1025];
    scanf("%[^\n]", message);

    if (strncmp(operation, "ENCODE", 6) == 0)
        encode(message, pseudo_random_number, rotors);
    else
        decode(message, pseudo_random_number, rotors);

    return (0);
}