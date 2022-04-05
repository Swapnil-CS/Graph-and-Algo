#include <stdio.h>
#include <stdlib.h>

int is_undirected(int n, int **adm)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((*(*(adm + i) + j)) != (*(*(adm + j) + i)))
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int **adm, n, i, j, u, v, t;
    do
    {
        printf("\nEnter ther number of nodes:");
        scanf("%d", &n);
    } while (n <= 0);

    adm = (int **)calloc(n, sizeof(int *));

    for (i = 0; i < n; i++)
    {
        *(adm + i) = (int *)calloc(n, sizeof(int));
    }
    if (adm == NULL)
    {
        printf("\n Allocation failed");
    }

    printf("\nEnter the edges for the graph:\n");
    do
    {
        printf("\n\tEnter the node pairs (u v) which you want to connect:");
        scanf("%d%d", &u, &v);
        (*(*(adm + u - 1) + (v - 1)))++;
        printf("\nDo you want to insert more number of edges? (1-yes/0-no):");
        scanf("%d", &u);
    } while (u != 0);

    printf("\nThe input graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", *(*(adm + i) + j));
        }
        printf("\n");
    }
    t = is_undirected(n, adm);
    if (t == 0)
    {
        printf("\nInput graph is directed");
    }
    else
    {
        printf("\nInput graph is undirected");
    }
    return 0;
}
