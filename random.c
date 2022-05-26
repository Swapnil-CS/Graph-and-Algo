#include<stdio.h>
#include<time.h>
int main()
{
    int lb =3,ub=12,num,i;
    srand(time(0));
    for(i=0;i<10;i++)
    {
        num=(rand()%(ub-lb+1))+lb;
        printf("%d\n",num);
    }
    return 0;
}