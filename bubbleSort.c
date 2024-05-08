#include <stdio.h>

void main()
{
    int x[5], i = 0, j, pos, tmp;
    printf("\nARRAY DATA:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &x[i]);
    }
    printf("\nBEFORE SORTING:");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", x[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(x[j]>x[j+1])
            {
                tmp=x[j];
                x[j]=x[j+1];
                x[j+1]=tmp;
            }
        }
    }
    printf("\nAFTER SORTING:\n");
    for(i=0;i<5;i++)
    {
        printf("%4d",x[i]);
    }
    return;
}    