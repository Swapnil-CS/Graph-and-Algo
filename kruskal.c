#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int src, end, wt;
} EDGE;

void sort(EDGE *, int);

int main()
{
    int **wtm, n, u, v, i, j, ecount = 0, w;
    do
    {
        printf("\nEnter the number of nodes:");
        scanf("%d", &n);
    } while (n <= 0);

    wtm = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        *(wtm + i) = (int *)calloc(n, sizeof(int));
    }
    if (wtm == NULL)
    {
        printf("Allocation failed\n");
        return 0;
    }
    do
    {
        printf("\nInput the node pair (u, v) where edge will be drawn:\t");
        scanf("%d%d", &u, &v);
        printf("\nEnter the weight of the edge to be drawn:");
        scanf("%d", &w);
        if (u != v)
        {
            (*(*(wtm + u - 1) + (v - 1))) += w;
            (*(*(wtm + v - 1) + (u - 1))) += w;
        }
        printf("\nDo you want to insert again (1 for yes / 0 for no)? ");
        scanf("%d", &u);
    } while (u != 0);

    printf("\nYour input adjacency matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", *(*(wtm + i) + j));
        }
        printf("\n");
    }
}