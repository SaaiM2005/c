#include<stdio.h>
int main()
{
	int x[10];
	int *p=x;
	int i=0;
	while(i<10)
	{
		printf("\n Data:");
		scanf("%d",p+i);
		i++;
	}
	printf("\n Data\n");
	for(i=0;i<10;i++)
		printf("%4d",*(p+i));
	return;
}
