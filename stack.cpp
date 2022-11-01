#include "stek.h"
#include <stdio.h>
#include <malloc.h>

void stek_start(struct stek* stek)
{
    stek -> data = (stek_type*)calloc(SIZE, sizeof(stek_type));
    for(int i = 0; i < SIZE; i++)
        stek -> data[i] = 0;
    stek -> depth = 0;
}

void input_commands()
{
    const char* push = "push";
    char command[30];
    scanf("%s", command); // строки нельзя просто так сравнивать
}

void stek_push(struct stek* stek, int i)
{
    stek -> data[stek -> depth] = i;
    stek -> depth++;
}

void stek_add(struct stek* stek)
{
    stek -> data[stek -> depth - 2] += stek -> data[stek -> depth - 1];
    stek -> depth--;
}

void stek_print(struct stek* stek)
{
    printf("========================\n");
    for(int i = 0; i < stek -> depth; i++)
    {

        printf("%d:  %d\n", i, stek -> data[i]);
    }
    printf("========================\n");
}

int stek_test(struct stek* stek)
{
    if(stek -> depth < 0)
        return 0;

    if(stek -> depth >= SIZE)
        return 0;

    return 1;
}
