#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *st = NULL; // head node pointer

// FUNCTION TO CREATE NODE
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

// FUNCTION TO GET LAST NODE
NODE *getLastNode()
{
    NODE *a = st; // NODE is a traversal pointer
    while (a->next != NULL)
        a = a->next;
    return a;
}

// FUNCTION TO ADD NEW NODE AT THE END
void addE(int d)
{
    NODE *a, *b;
    a = createNode(d);
    if (st == NULL) // st = start
        st = a;
    else
    {
        b = getLastNode();
        b->next = a;
    }
}

// FUNCTION TO ADD NEW NODE AT BEGINNING
void addB(int d)
{
    NODE *a = createNode(d);
    a->next = st;
    st = a;
}

// FUNCTION TO DISPLAY LIST DATA
void display()
{
    NODE *a = st;
    if (st == NULL)
    {
        printf("\nEmpty list.");
    }
    else
    {
        printf("\nDATA:\n");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

int main()
{
    int opt, d;
    while (1)
    {
        printf("\nMENU:\n 1.ADD AT END\n 2.ADD AT BEGIN\n 3.DISPLAY\n 4.EXIT\n OPTION: ");
        scanf("%d", &opt);
        if (opt < 1 || opt > 4)
            break;
        switch (opt)
        {
        case 1:
            printf("\nADD DATA AT END: ");
            scanf("%d", &d);
            addE(d);
            break;
        case 2:
            printf("\nADD DATA AT BEGIN: ");
            scanf("%d", &d);
            addB(d);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0); // Exit the program gracefully
        }
    }
    return 0;
}
