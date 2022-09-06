#include <stdio.h>
#include <stdlib.h>

#define INF 99999

void prims(int **, int *, int);

int main()
{
	int **adj, *selected;
	int n, i, j, u, v, wt, ch;

	do
	{
		printf("\nEnter number of nodes: ");
		scanf("%d", &n);
	} while (n <= 0);

	adj = (int **)calloc(n, sizeof(int *));
	for (i = 0; i < n; i++)
	{
		*(adj + i) = (int *)calloc(n, sizeof(int));
	}
	selected = (int *)calloc(n, sizeof(int));

	if (adj == NULL || selected == NULL)
	{
		printf("\n\nMemory allocation failed.");
		exit(0);
	}

	printf("\nEnter the edges for the graph:\n");
	do
	{
		printf("\nEnter the node pairs (u v) which you want to connect: ");
		scanf("%d%d", &u, &v);
		printf("\nEnter the corresponding edge weight: ");
		scanf("%d", &wt);
		*(*(adj + u - 1) + v - 1) = wt;
		*(*(adj + v - 1) + u - 1) = wt;
		printf("\nDo you want to insert more number of edges? (1-yes/0-no):");
		scanf("%d", &u);
	} while (u != 0);
	printf("\nInput Graph is:");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%d\t", *(*(adj + i) + j));
		}
	}

	prims(adj, selected, n);

	free(adj);
	free(selected);

	return 0;
}

void prims(int **a, int *s, int v)
{
	int n = 0, x, y, i, j, min, cost = 0;

	*s = 1;
	printf("\nSpanning Tree is:\n");
	printf("\nEdge : Weight\n");
	while (n < v - 1)
	{
		x = 0;
		y = 0;
		min = INF;

		for (i = 0; i < v; i++)
		{
			if (*(s + i) != 0)
			{
				for (j = 0; j < v; j++)
				{
					if (*(s + j) == 0 && *(*(a + i) + j) != 0)
					{
						if (min > *(*(a + i) + j))
						{
							min = *(*(a + i) + j);
							x = i;
							y = j;
						}
					}
				}
			}
		}

		printf("%d - %d : %d\n", x + 1, y + 1, *(*(a + x) + y));
		*(s + y) = 1;
		n++;
		cost += *(*(a + x) + y);
	}
	printf("\nSpanning tree cost: %d", cost);
}
