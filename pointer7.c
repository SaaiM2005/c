#include<stdio.h>
void main()
{
	int x [5];
	int *p=x+0;
	int *q=x+4;
	{
		printf("\n Enter Number:");
		scanf("%d",p);
		p=p+1;
	}
	p=x+0;
	while(p<=q)
	{
		printf("%4d",*p);
		p++;
	}
	return;
}
