#include <stdio.h>
#include <stdlib.h>
void bfs(int **, int, int);
void dfs(int **, int, int);
int main()
{
    int **i_adjmatrix, i_number_of_nodes, i_itervar, i_itervar1, i_u, i_v, i_ch;
    do
    {
        printf("\nEnter ther number of nodes:");
        scanf("%d", &i_number_of_nodes);
    } while (i_number_of_nodes <= 0);

    i_adjmatrix = (int **)calloc(i_number_of_nodes, sizeof(int *));

    for (i_itervar = 0; i_itervar < i_number_of_nodes; i_itervar++)
    {
        i_adjmatrix[i_itervar] = (int *)calloc(i_number_of_nodes, sizeof(int));
    }

    printf("\nEnter the edges for the graph:\n");
    do
    {
        printf("\n\tEnter the node pairs (u v) which you want to connect:");
        scanf("%d%d", &i_u, &i_v);
        i_adjmatrix[i_u - 1][i_v - 1] = 1;
        i_adjmatrix[i_v - 1][i_u - 1] = 1;
        printf("\nDo you want to insert more number of edges? (1-yes/0-no):");
        scanf("%d", &i_u);
    } while (i_u != 0);

    printf("\nThe input graph is:\n");
    for (i_itervar = 0; i_itervar < i_number_of_nodes; i_itervar++)
    {
        for (i_itervar1 = 0; i_itervar1 < i_number_of_nodes; i_itervar1++)
        {
            printf("%d ", i_adjmatrix[i_itervar][i_itervar1]);
        }
        printf("\n");
    }

    do
    {
        printf("\n\t1. BFS");
        printf("\n\t2. DFS");
        printf("\n\t3. Exit");
        printf("\n Enter your choice:");
        scanf("%d", &i_ch);

        switch (i_ch)
        {
        case 1:
            printf("\nEnter the start node:");
            scanf("%d", &i_u);
            bfs(i_adjmatrix, i_number_of_nodes, i_u - 1);
            break;
        case 2:
            printf("\nEnter the start node:");
            scanf("%d", &i_u);
            dfs(i_adjmatrix, i_number_of_nodes, i_u - 1);
            break;
        case 3:
            break;
        default:
            printf("\nEnter proper choice...!");
        }
    } while (i_ch != 3);

    free(i_adjmatrix);

    return 0;
}

void dfs(int **a, int n, int s)
{
    int *d, *parent, *stk;
    int i, k, top = -1, u, v, count = 0;

    d = (int *)calloc(n, sizeof(int));
    parent = (int *)calloc(n, sizeof(int));
    stk = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        d[i] = -1;
        parent[i] = -1;
    }
    d[s] = 0;
    stk[++top] = s;

    while (top != -1)
    {
        v = stk[top--];
        count++;
        for (u = 0; u < n; u++)
        {
            if (a[v][u] == 1)
            {
                if (d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    parent[u] = v;
                    stk[++top] = u;
                }
            }
        }
    }

    if (count == n)
    {
        printf("\nGraph is connected\n");
    }
    else
    {
        printf("\nGraph is not connected\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("\nDistance from node %d to node %d is %d and path between them is", s + 1, i + 1, d[i]);
        if (i != s)
        {
            printf(" %d ", i + 1);
            k = i;
            while (parent[k] != -1)
            {
                k = parent[k];
                printf("-> %d ", k + 1);
            }
        }
    }

    free(d);
    free(parent);
    free(stk);
}

void bfs(int **a, int n, int s)
{
    int *d, *parent, *q;
    int i, k, front = -1, rear = -1, u, v, count = 0;

    d = (int *)calloc(n, sizeof(int));
    parent = (int *)calloc(n, sizeof(int));
    q = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        d[i] = -1;
        parent[i] = -1;
    }
    d[s] = 0;
    q[++rear] = s;

    while (front != rear)
    {
        v = q[++front];
        count++;
        for (u = 0; u < n; u++)
        {
            if (a[v][u] == 1)
            {
                if (d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    parent[u] = v;
                    q[++rear] = u;
                }
            }
        }
    }

    if (count == n)
    {
        printf("\nGraph is connected\n");
    }
    else
    {
        printf("\nGraph is not connected\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("\nDistance from node %d to node %d is %d and path between them is", s + 1, i + 1, d[i]);
        if (i != s)
        {
            printf(" %d ", i + 1);
            k = i;
            while (parent[k] != -1)
            {
                k = parent[k];
                printf("-> %d ", k + 1);
            }
        }
    }

    free(d);
    free(parent);
    free(q);
}