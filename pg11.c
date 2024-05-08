#include<stdio.h>
int input(int*a,int n)
{
	int i=0;
	printf("\n Data:\n");
	while(i<n)
	{
		scanf("5d",(a+i));
		i++;
	}
}
void display(int *a,int n)
{
	int i=0;
	printf("\nData:\n");
	while(i<n)
	{
		printf("%4d",*(a+i));
		i++;
	}
}
void main()
{
	void(*ptr)(int*,int);
	int x[5];
	ptr=input;
	(*ptr)(x,5);
	ptr=display;
	(*ptr)(x,5);
	return;
}
