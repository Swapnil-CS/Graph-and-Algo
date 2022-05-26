#include <stdio.h>
#include <stdlib.h>

typedef struct neighbour
{
    int data;
    struct neighbour *next;
} NEIG;

typedef struct node
{
    int data;
    struct node *next;
    NEIG *nei;
} NODE;

NODE *createnode(int i)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    p->data = i;
    p->next = NULL;
    p->nei = NULL;
    return p;
}

NEIG *createneighbour(int neg)
{
    NEIG *p;
    p = (NEIG *)malloc(sizeof(NEIG));
    p->data = neg;
    p->next = NULL;
    return p;
}

int main()
{
    NODE *new, *start = NULL, *temp;
    NEIG *newneg;
    int i, ch, neg, count;
    printf("\n Do you want to insert nodes for the graph (1 for yes/ 0 for no)?");
    scanf("%d", &ch);
    i = 0;
    while (ch == 1)
    {
        i++;
        if (start == NULL)
        {
            new = createnode(i);
            start = new;
        }
        else
        {
            new->next = createnode(i);
            new = new->next;
        }
        printf("\nNode number %d created", i);
        printf("\nDo you want to insert node again(1 for yes/0 for no)?");
        scanf("%d", &ch);
    }

    temp = start;
    count = i;
    i = 1;
    while (i <= count)
    {
        printf("\nDo you want to insert neighbour for node number %d (1 for yes/0 for no)?", i);
        scanf("%d", &ch);
        while (ch == 1)
        {
            do
            {
                printf("\nEnter the node number which you want to add as neighbour:");
                scanf("%d", &neg);
            } while (neg <= 0 || neg > count || neg == i);
            if (temp->nei == NULL)
            {
                temp->nei = createneighbour(neg);
                newneg = temp->nei;
            }
            else
            {
                newneg->next = createneighbour(neg);
                newneg = newneg->next;
            }
            printf("\nDo you want to insert neighbour for node number %d again (1 for yes/0 for no)?", i);
            scanf("%d", &ch);
        }
        temp = temp->next;
        i++;
    }

    printf("\nYour input adjacency list is:\n");
    temp = start;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        newneg = temp->nei;
        while (newneg != NULL)
        {
            printf("->%d", newneg->data);
            newneg = newneg->next;
        }
        temp = temp->next;
        printf("\n");
    }

    free(start);

    return 0;
}