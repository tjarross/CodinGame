#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

void free_split(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

int splitlen(char **split)
{
    int i;

    i = 0;
    while (split[i])
        ++i;
    return (i);
}

static int count_words(const char *str, char delim)
{
    int i;
    int word;

    i = -1;
    word = 1;
    while (str[++i])
        if (str[i] == delim)
            ++word;
    return (word);
}

static int get_wordlen(const char *str, char delim)
{
    int i;

    i = 0;
    while (str[i] != delim && str[i])
        ++i;
    return (i);
}

char **strsplit(const char *str, char delim)
{
    char **dest;
    int words;
    int i;
    int j;
    int word_len;

    i = 0;
    j = -1;
    if (!str || !isascii(delim) || !(words = count_words(str, delim)))
        return (NULL);
    if (!(dest = (char **)malloc(sizeof(char *) * (words + 1))))
        return (NULL);
    dest[words] = NULL;
    while (++j < words)
    {
        word_len = get_wordlen(str + i, delim);
        if (!(dest[j] = (char *)malloc(sizeof(char) * (word_len + 1))))
            return (NULL);
        dest[j] = strncpy(dest[j], str + i, word_len);
        dest[j][word_len] = '\0';
        i += word_len + 1;
    }
    return (dest);
}

void replace(char *str, char in, char out)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == in)
            str[i] = out;
    }
}

int main(void)
{
    char s_LON[51];
    scanf("%s", s_LON);

    char s_LAT[51];
    scanf("%s", s_LAT);

    replace(s_LON, ',', '.');
    replace(s_LAT, ',', '.');

    double LON = atof(s_LON);
    double LAT = atof(s_LAT);

    int N;
    scanf("%d", &N);
    fgetc(stdin);

    char closest[1024];
    int closest_distance = -1;
    char **infos;
    int split_size;
    for (int i = 0; i < N; i++)
    {
        char DEFIB[257] = {0};
        scanf("%[^\n]", DEFIB);
        fgetc(stdin);

        infos = strsplit(DEFIB, ';');
        split_size = splitlen(infos);

        replace(infos[split_size - 2], ',', '.');
        replace(infos[split_size - 1], ',', '.');

        double d_lon = atof(infos[split_size - 2]);
        double d_lat = atof(infos[split_size - 1]);

        double x = (d_lon - LON) * cos((LAT + d_lat) / 2.f);
        double y = (d_lat - LAT);
        double d = sqrt(x * x + y * y) * 6371;

        if (closest_distance == -1)
        {
            closest_distance = d;
            strcpy(closest, infos[1]);
        }
        else if (d < closest_distance)
        {
            closest_distance = d;
            strcpy(closest, infos[1]);
        }
        free_split(infos);
    }
    printf("%s\n", closest);

    return (0);
}