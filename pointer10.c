//reverse 
#include<stdio.h>
void input(int *a,int n)
{
	int i=0;
	printf("\n Data:\n");
	while(i<n)
	{
		scanf("%d",(a+i));
		i++;
	}	
}
void display(int *a,int n)
{
	int i=0;
	printf("\n Data:\n");
	while(i<n)
	{
		printf("%4d",*(a+i));
		i++;
	}
}
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
int main()
{
	int x[5];
	int i,j;
	input(x,5);
	display(x,5);
	for(i=0,j=4;i<j;i++,j--)
		swap(x+i,x+j);
	display(x,5);
	return;
}























