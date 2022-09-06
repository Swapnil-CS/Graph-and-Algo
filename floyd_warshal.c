#include <stdio.h>
#include <stdlib.h>
void floyd(int **, int);
void warshal(int **, int);
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

	/*printf("\nThe input graph is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", adm[i][j]);
		}
		printf("\n");
	}	*/

	do
	{
		printf("\n\t1. Floyd");
		printf("\n\t2. Warshal");
		printf("\n\t3. Exit");
		printf("\n Enter your choice:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
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

			floyd(adm, n);
			break;
		case 2:
			printf("\nEnter the edges for the graph:\n");
			do
			{
				printf("\n\tEnter the node pairs (u v) which you want to connect:");
				scanf("%d%d", &u, &v);
				adm[u - 1][v - 1] = 1;
				printf("\nDo you want to insert more number of edges? (1-yes/0-no):");
				scanf("%d", &u);
			} while (u != 0);

			warshal(adm, n);
			break;
		case 3:
			break;
		default:
			printf("\nEnter proper choice...!");
		}
	} while (ch != 3);

	free(adm);

	return 0;
}

void floyd(int **a, int n)
{
	int i, j, k;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (a[i][k] + a[k][j] < a[i][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}

	printf("\nThe cost of all pair shortest path are:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void warshal(int **a, int n)
{
	int i, j, k;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i != j)
				{
					a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
				}
			}
		}
	}

	printf("\nThe cost of all pair shortest path are:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
