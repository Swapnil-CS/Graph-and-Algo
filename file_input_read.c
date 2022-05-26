#include<stdio.h>
#include<stdlib.h>
int main()
{
    int v_count,e_count,x,x1=9999,y,i=0;
    int *vptr,*eptr;
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp,"%d\n",&v_count);
    fscanf(fp,"%d\n",&e_count);
    vptr = (int*)calloc(v_count,sizeof(int));
    eptr = (int*)calloc(2*e_count,sizeof(int));
    printf("%d\n%d\n",v_count,e_count);
    while(!feof(fp))
    {
        fscanf(fp,"%d, %d\n",&x,&y);
        // printf("%d %d\n",x,y);
        if(x!=x1)
            vptr[x] = i;
        eptr[i] = y;
        i++;
        x1=x;
    }
    fclose(fp);
    printf("VPTR:\n");
    for(i=0;i<v_count;i++)
    {
        printf("%d\t",vptr[i]);
    }
    printf("\nEPTR:\n");
    for(i=0;i<2*e_count;i++)
    {
        printf("%d\t",eptr[i]);
    }
    free(vptr);
    free(eptr);
    return 0;
}