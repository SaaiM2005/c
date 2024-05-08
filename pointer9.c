#include<stdio.h>
int main()
{
	int x[10];
	void input(int *,int);
	void display(int *,int);
	input(x,10);
	display(x,10);
	return;
}
void input(int *p,int n)
{
	int i=0;
	printf("\n Data\n");
	while(i<n)
	{
		scanf("%d",p+i);
		i++;
	}
}
void display(int *q,int n)
{
	int i=0;
	printf("\n Data\n");
	while(i<n)
	{
		printf("%4d",*(q+i));
		i++;
	}
}
