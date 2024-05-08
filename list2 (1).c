#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}NODE;

NODE *st=NULL; //Head Node Pointer
//fn to create NODE
NODE * createNode(int d)
{
	NODE *a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}

//fn to get last NODE
NODE * getLastNode()
{
    NODE *a=st;
    while(a->next!=NULL)
    a=a->next;
    return a;
}

//fn to add new node at end
void addE(int d)
{
	NODE *a,*b;
	a=createNode(d);
	if(st==NULL)
	{
		st=a;
	}
	else
	{
		b=getLastNode();
		b->next=a;
	}
}

//fn to add new node at begin

void addB(int d)
{
    NODE *a =createNode(d);
	a->next=st;
	st=a;
}

//fn to display list data
void display()
{
	NODE *a=st;
	if(st==NULL)
	{
		printf("\n List Empty\n");
	}
	else
	{
		printf("\n Data\n");
		while (a != NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}
}
//function to count nodes.
int count()
{
	NODE *a=st;
	int cnt=0;
	while(a!=NULL)
	{
		cnt++;
		a=a->next;
	}
	return cnt;
}
//function to compute data sum.
int sum()
{
	NODE *a=st;
	int tot=0;
	while(a!=NULL)
	{
		tot=tot+a->data;
		a=a->next;
	}
	return tot;
}
//function to find out minimun data found from list.
int minData()
{
    NODE *a=st;
    int min=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data<min)
            min=a->data;
    }
    return min;
}

//fn to fint out minimum data from the list
int maxData()
{
    NODE *a=st;
    int max=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data>max)
            max=a->data;
    }
    return max;
}

void main()
{
	int opt,d;
	while(1)
	{
		printf("\nMenu\n1.ADD AT END\n2.ADD AT BEGINING\n3.DISPLAY\n4.COUNT\n5.SUM OF DATA\n6.MINIMUM DATA\n7.MAXIMUM DATA\n8.EXIT\nOPTION: ");
		scanf("%d",&opt);
		if(opt<1||opt>7)
			break;
		switch(opt)
		{
			case 1:
			printf("\nAdd Data at End: ");
			scanf("%d",&d);
			addE(d);
			break;

			case 2:
			printf("\nAdd Data at Begining: ");
			scanf("%d",&d);
			addB(d);
			break;

			case 3:
			display();
				break;
			case 4:
				printf("\n Node count:%d",count());
				break;
			case 5:
				printf("\n Data sum:%d",sum());
			case 6:
            if(st!=NULL)
                printf("MINIMUM DATA: %d",minData());
            break;

            case 7:
            if(st!=NULL)
                printf("MAXIMUM DATA: %d",maxData());
            break;
				
				
		}
	}
}