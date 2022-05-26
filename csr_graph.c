#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int v_count;
    int e_count;
    int *vptr;
    int *eptr;
} Graph;

void print_graph(Graph *csr)
{
    int i = 0;
    printf("\nNumber of vertices: %d\n", csr->v_count);
    printf("\nNumber of edges: %d\n", csr->e_count);
    printf("\nVPTR:\n\n");
    for (i = 0; i < csr->v_count; i++)
    {
        printf("|%d| ", csr->vptr[i]);
    }
    printf("\n\nEPTR:\n\n");
    for (i = 0; i < 2 * csr->e_count; i++)
    {
        printf("|%d| ", csr->eptr[i]);
    }
}

int gen_randnei(Graph *csr, int start, int end)
{
    int x, i = 0;

    x = (rand() % (end - start + 1)) + start;
    printf("%d\t", csr->eptr[x]);

    return csr->eptr[x];
}

Graph *CSR(char *file_name)
{
    Graph *csr;
    FILE *fp;
    int left_v, right_v, prev_v = -1, count = 0, end;
    int i = 0, j = 0, v;

    csr = (Graph *)malloc(sizeof(Graph));
    if (csr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }

    fp = fopen(file_name, "r");
    fscanf(fp, "%d\n%d\n", &csr->v_count, &csr->e_count);

    csr->vptr = (int *)calloc(csr->v_count, sizeof(int));
    if (csr->vptr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }
    csr->eptr = (int *)calloc(2 * csr->e_count, sizeof(int));
    if (csr->eptr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d,%d\n", &left_v, &right_v);
        if (left_v != prev_v)
        {
            csr->vptr[left_v] = i;
        }
        csr->eptr[i] = right_v;
        i++;
        prev_v = left_v;
    }
    fclose(fp);
    print_graph(csr);
    int p;
    printf("\nEnter the population: ");
    scanf("%d", &p);
    int **pop;
    pop = (int **)calloc(p, sizeof(int *));
    for (i = 0; i < p; i++)
    {
        pop[i] = (int *)calloc(csr->v_count, sizeof(int));
    }
    srand(time(0));
    printf("\nSolution Set:--\n");
    while (count < p)
    {
        printf("\n");

        for (v = 0; v < csr->v_count; v++)
        {
            end = (v == csr->v_count - 1) ? 2 * csr->e_count : csr->vptr[v + 1];
            pop[count][v] = gen_randnei(csr, csr->vptr[v], end - 1);
        }
        count++;
    }
    return csr;
}

int main()
{
    char *file_name;
    Graph *csr;
    file_name = "input2.txt";
    csr = CSR(file_name);
    free(csr);
}
