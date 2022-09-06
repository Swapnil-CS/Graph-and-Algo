#include <stdio.h>
#include <stdlib.h>
void dijkstra(int **, int);
int main()
{
    int **adm, n, i, j, u, v, ch, wt;
    do
    {
        printf("\nEnter ther number of nodes:");
        scanf("%d", &n);
    } while (n <= 0);

    adm = (int **)calloc(n, sizeof(int *));

    for (i = 0; i < n; i++)
    {
        adm[i] = (int *)calloc(n, sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                adm[i][j] = 9999;
            }
        }
    }

    printf("\nEnter the edges for the graph:\n");
    do
    {
        printf("\n\tEnter the node pairs (u v) which you want to connect:");
        scanf("%d%d", &u, &v);
        printf("\n\tEnter the corresponding edge weight:");
        scanf("%d", &wt);
        adm[u - 1][v - 1] = wt;
        adm[v - 1][u - 1] = wt;
        printf("\nDo you want to insert more number of edges? (1-yes/0-no):");
        scanf("%d", &u);
    } while (u != 0);

    dijkstra(adm, n);
}

void dijkstra(int **a, int n)
{
    int *l;
    int i;
    l = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        l[i] = 9999;
    }
}