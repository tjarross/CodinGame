#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_pair
{
    char key[11];
    char value[51];
} t_pair;

int cmpfn(const void *a, const void *b)
{
    t_pair *pair1 = (t_pair *)a;
    t_pair *pair2 = (t_pair *)b;
    return (strcasecmp(pair1->key, pair2->key));
}

int main(void)
{
    t_pair *map;

    // Number of elements which make up the association table.
    int N;
    scanf("%d", &N);

    map = (t_pair *)malloc(sizeof(t_pair) * N);

    // Number Q of file names to be analyzed.
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < N; i++)
        scanf("%s%s", map[i].key, map[i].value);
    fgetc(stdin);
    qsort(map, N, sizeof(t_pair), cmpfn);

    char *ext;
    for (int i = 0; i < Q; i++)
    {
        // One file name per line.
        char FNAME[257];
        scanf("%[^\n]", FNAME);
        fgetc(stdin);
        int j;
        int found = 0;
        if ((ext = strrchr(FNAME, '.')) == NULL)
        {
            printf("UNKNOWN\n");
            continue;
        }
        t_pair *match;
        t_pair cmp;
        strcpy(cmp.key, ext + 1);
        if ((match = bsearch(&cmp, map, N, sizeof(t_pair), cmpfn)) != NULL)
        {
            found = 1;
            printf("%s\n", match->value);
        }
        else if (found == 0)
            printf("UNKNOWN\n");
    }

    free(map);

    return (0);
}