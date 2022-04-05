#include <stdio.h>
#include <stdlib.h>

int is_simple(int, int **);
int count_loop(int, int **);
int parallel_edge_count(int, int **);

int main()
{
	int **adm, n, u, v;
	do
	{
		printf("Enter the number of nodes of the input graph:\t");
		scanf("%d", &n);
	} while (n <= 0);

	adm = (int **)calloc(n, sizeof(int *));
	for (u = 0; u < n; u++)
	{
		*(adm + u) = (int *)calloc(n, sizeof(int));
	}
	if (adm == NULL)
	{
		printf("Allocation failed\n");
		return 0;
	}
	do
	{
		printf("Input the node pair (u, v) where edge will be drawn:\t");
		scanf("%d%d", &u, &v);
		if (u == v)
		{
			(*(*(adm + u - 1) + (v - 1))) += 2;
		}
		else
		{
			(*(*(adm + u - 1) + (v - 1)))++;
			(*(*(adm + v - 1) + (u - 1)))++;
		}
		printf("Do you want to insert again (1 for yes / 0 for no)?\t");
		scanf("%d", &u);
	} while (u != 0);

	printf("Your input adjacency matrix is:\n");
	for (u = 0; u < n; u++)
	{
		for (v = 0; v < n; v++)
		{
			printf("%d ", *(*(adm + u) + v));
		}
		printf("\n");
	}
	u = is_simple(n, adm);
	if (u == 1)
	{
		printf("The input graph is simple\n");
	}
	else
	{
		printf("The input graph is not simple\n");
		v = count_loop(n, adm);
		printf("The number of loops in the graph is %d\n", v);
		u = parallel_edge_count(n, adm);
		printf("The number of parallel edges is %d\n", u);
	}
	free(adm);
	return 0;
}
int is_simple(int n, int **adm)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (*(*(adm + i) + i) == 0)
		{
			for (j = 0; j < n; j++)
			{
				if (*(*(adm + i) + j) > 1)
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int count_loop(int n, int **adm)
{
	int i, loop = 0;
	for (i = 0; i < n; i++)
	{
		loop = loop + (*(*(adm + i) + i));
	}
	return loop / 2;
}

int parallel_edge_count(int n, int **adm)
{
	int i, j, p_edge = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(*(adm + i) + j) > 1)
			{
				p_edge = p_edge + (*(*(adm + i) + j)) - 1;
			}
		}
	}
	return p_edge;
}