#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int L;
    scanf("%d", &L);

    int H;
    scanf("%d", &H);
    fgetc(stdin);

    char T[257];
    scanf("%[^\n]", T);
    fgetc(stdin);

    for (int i = 0; i < H; i++)
    {
        char ROW[1025];
        scanf("%[^\n]", ROW);
        fgetc(stdin);

        for (int j = 0; j < strlen(T); ++j)
        {
            if (!isalpha(T[j]))
                printf("%.*s", L, ROW + (L * 26));
            else
                printf("%.*s", L, ROW + (L * (toupper(T[j]) - 'A')));
        }
        printf("\n");
    }
    return (0);
}