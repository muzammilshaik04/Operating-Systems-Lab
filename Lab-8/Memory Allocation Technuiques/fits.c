#include <stdio.h>

void firstFit(int bs[], int b, int ps[], int p)
{
    int block[20], alloc[20];

    for(int i = 0; i < b; i++)
        block[i] = bs[i];

    for(int i = 0; i < p; i++)
        alloc[i] = -1;

    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(block[j] >= ps[i])
            {
                alloc[i] = j;
                block[j] -= ps[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int bs[], int b, int ps[], int p)
{
    int block[20], alloc[20];

    for(int i = 0; i < b; i++)
        block[i] = bs[i];

    for(int i = 0; i < p; i++)
        alloc[i] = -1;

    for(int i = 0; i < p; i++)
    {
        int best = -1;

        for(int j = 0; j < b; j++)
        {
            if(block[j] >= ps[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            alloc[i] = best;
            block[best] -= ps[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int bs[], int b, int ps[], int p)
{
    int block[20], alloc[20];

    for(int i = 0; i < b; i++)
        block[i] = bs[i];

    for(int i = 0; i < p; i++)
        alloc[i] = -1;

    for(int i = 0; i < p; i++)
    {
        int worst = -1;

        for(int j = 0; j < b; j++)
        {
            if(block[j] >= ps[i])
            {
                if(worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            alloc[i] = worst;
            block[worst] -= ps[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blocks, processes;

    printf("Enter number of blocks: ");
    scanf("%d", &blocks);

    int blockSize[20];

    printf("Enter block sizes:\n");
    for(int i = 0; i < blocks; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    int processSize[20];

    printf("Enter process sizes:\n");
    for(int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);

    firstFit(blockSize, blocks, processSize, processes);
    bestFit(blockSize, blocks, processSize, processes);
    worstFit(blockSize, blocks, processSize, processes);

    return 0;
}