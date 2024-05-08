//ARRAY IMPLEMENTATION OF STACK THAT CONTAINS CHARACTER DATA
#define m 5
#include<stdio.h>
#include<stdlib.h>
typedef struct cstack
{
    char arr[m];
    int top;
}CSTK;
void init(CSTK *t)
{
    t->top=-1;
}
int isEmpty(CSTK *t)
{
    return t->top==-1;
}
int isFull(CSTK *t)
{
    return (t->top==m-1);
}
//push function
void push(CSTK *t,char ch)
{
    if(isFull(t))
    {
        printf("\nOVERFLOW.");
    }
    else
    {
        t->top++;
        t->arr[t->top]=ch;
    }
}
//pop function
void pop(CSTK *t)
{
    if(isEmpty(t))
    {
        printf("\nUNDERFLOW.");
    }
    else
    {
        t->top--;
    }
}
//display
void display(CSTK *t)
{
    int i=t->top;
    if(isEmpty(t))
    {
        printf("\nEMPTY STACK.");
    }
    else
    {
        printf("\nSTACK:\n");
        while(i>=0)
        {
            printf("%4c",t->arr[i]);
            i--;
        }
    }
}
int main()
{
    CSTK p;
    int opt;
    char ch;
    init(&p);
    while(1)
    {
         printf("\nMENU.\n1.PUSH.\n2.POP.\n3.DISPLAY.\n4.EXIT.\nOPTION:");
         scanf("%d",&opt);
         if(opt>3)
         {
            break;
         }
         switch(opt)
         {
            case 1:
                printf("\nTYPE CHARACTER:");
                scanf(" %c",&ch);
                push(&p,ch);
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                display(&p);
        }
    }
}