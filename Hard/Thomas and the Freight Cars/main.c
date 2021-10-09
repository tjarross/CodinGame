#include <stdlib.h>
#include <stdio.h>

typedef struct s_memory
{
    int high;
    int low;
    int max_cars;
} t_memory;

t_memory *g_m = NULL;
int g_memory_length = 0;

int g_max_car;

int cmpfn(const void *a, const void *b)
{
    t_memory *m1 = (t_memory *)a;
    t_memory *m2 = (t_memory *)b;
    return ((1000 * (m1->high - m2->high) + (m1->low - m2->low)));
}

int search_node(int high, int low)
{
    t_memory key;

    key.high = high;
    key.low = low;

    t_memory *m = bsearch(&key, g_m, g_memory_length, sizeof(t_memory), cmpfn);

    return (m ? m->max_cars : -1);
}

void register_node(int high, int low, int max_cars)
{
    if (search_node(high, low) != -1)
        return;

    g_m = realloc(g_m, sizeof(t_memory) * (g_memory_length + 1));

    g_m[g_memory_length].high = high;
    g_m[g_memory_length].low = low;
    g_m[g_memory_length].max_cars = max_cars;

    ++g_memory_length;

    qsort(g_m, g_memory_length, sizeof(t_memory), cmpfn);
}

int rec_solve(const int *array, int size, int index, int high, int low, int current_max)
{
    if (current_max + (size - index) < g_max_car)
        return (1);

    int local_max = 1;
    int result;

    for (int i = index; i < size; ++i)
    {
        if (array[i] > high || array[i] < low)
        {
            if ((result = search_node(high, low)) == -1)
            {
                if (array[i] > high)
                    result = 1 + rec_solve(array, size, i + 1, array[i], low, current_max + 1);
                else if (array[i] < low)
                    result = 1 + rec_solve(array, size, i + 1, high, array[i], current_max + 1);
            }

            if (result > local_max)
                local_max = result;
            if (g_max_car < local_max)
                g_max_car = local_max;
        }
    }

    register_node(high, low, local_max);
    return local_max;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int *t = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        int w;
        scanf("%d", &w);
        t[i] = w;
    }

    for (int i = 0; g_max_car < N - i; ++i)
        rec_solve(t, N, i, t[i], t[i], 1);
    printf("%d\n", g_max_car);

    free(t);
    free(g_m);

    return (0);
}