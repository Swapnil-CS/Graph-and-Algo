#include <stdio.h>
#include <stdlib.h>
#define infinity 9999999
void prims(int **, int **, int);

int main()
{
    int **a, **spanning_tree, s, d, w, n;
    do
    {
        printf("\nenter the number of vertices:\t");
        scanf("%d", &n);
    } while (n < 0);

    a = (int **)calloc(n, sizeof(int *));
    spanning_tree = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (int *)calloc(n, sizeof(int));
        *(spanning_tree + i) = (int *)calloc(n, sizeof(int));
    }
    if (a == NULL || spanning_tree == NULL)
    {
        printf("\nallocation fail");
        return 0;
    }
    else
    {

        do
        {
            printf("\n\tenter the vertex pair for which there is an edge: ");
            scanf("%d%d", &s, &d);
            printf("\n\tenter the corresponding edge weight: ");
            scanf("%d", &w);
            a[s - 1][d - 1] = w;
            a[d - 1][s - 1] = w;
            printf("\n do  you want to enter more no edges:[0/1]");
            scanf("%d", &s);
        } while (s != 0);

        prims(a, spanning_tree, n);
        free(a);
        free(spanning_tree);

        return 0;
    }
}

void prims(int **a, int **spanning_tree, int n)
{
    int *s, i, j, x, y, edge = 0, cost;
    s = (int *)calloc(n, sizeof(int));

    if (s == NULL)
    {
        printf("\nallocation fail");
    }
    else
    {
        s[0] = 1;

        printf("\nthe input graph is:\n");
        for (i = 0; i < n; i++)
        {
            printf("\n");
            for (j = 0; j < n; j++)
            {
                printf("%d", a[i][j]);
                printf("\t");
            }
        }
        cost = 0;
        while (edge < n - 1)
        {

            x = y = 0;
            int min = infinity;
            for (i = 0; i < n; i++)
            {

                if (s[i] == 1)
                {
                    for (j = 0; j < n; j++)
                    {

                        if (s[j] == 0 && a[i][j] != 0)
                        {
                            if (min > a[i][j])
                            {
                                min = a[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            s[y] = 1;
            spanning_tree[x][y] = min;
            spanning_tree[y][x] = min;
            edge++;
            cost = cost + spanning_tree[x][y];
        }
    }

    printf("\n\n\n\nspanning tree is: \n\n\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d", spanning_tree[i][j]);
            printf("\t");
        }
    }
    printf("\ncost is %d", cost);
    printf("\n");

    free(s);
}
