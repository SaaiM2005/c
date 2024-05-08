#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}NODE;
typedef struct last
{
    NODE *rt;
    NODE *curr;
    NODE *prnt;
}BST;
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->left=a->right=NULL;
    return a;
}
void init(BST *t)
{
    t->rt=NULL;
    t->prnt=NULL;
    t->curr=NULL;
}
void createBST(BST *t)
{
    NODE *p,*q;
    int d;
    while(1)
    {
        printf("\nDATA:");
        scanf("%d",&d);
        if(d>=0)
            break;
        if(t->rt==NULL)
            t->rt=createNode(d);
        else
        {
            p=t->rt;
            while(1)
            {
                if(d<p->data)
                {
                    if(p->left==NULL)
                    {
                        p->left=createNode(d);
                        break;
                    }
                    else
                        p=p->left;
                    }
                    else
                    {
                        if(p->right==NULL)
                        {
                            p->right=createNode(d);
                            break;
                        }
                        else
                        p=p->right;
                    }
            }
        }
    }
}
void preorder(NODE *a)
{
    if(a!=NULL)
    {
        printf("%4d",a->data);
        preorder(a->left);
        preorder(a->right);
    }
    else
        return;
}
void inorder(NODE *a)
{
    if(a!=NULL)
    {
        inorder(a->left);
        printf("%4d",a->data);
        inorder(a->right);
    }
    else
        return;
}
void postorder(NODE *a)
{
    if(a!=NULL)
    {
        postorder(a->left);
        postorder(a->right);
        printf("%4d",a->data);
    }
    else
        return;

}
int search(BST *t,int sv)
{
    int flg=0;
    NODE *a=t->rt;
    while(1)
    {
        if(a->data==sv)
        {
            flg=1;
            t->curr=a;
            break;
        }
        else
        {
            if(sv<a->data)
            {
                if(a->left==NULL)
                {
                    break;
                }
                b->prnt=a;
                a=a->left;
            }  
            else
            {
                if(a->right==NULL)
                    break;
                t->prnt=a;
                a=a->right;
            } 
        }
    }
    return flg;
}
void main()
{
    int opt,d;
    BST p;
    init(&p);
    while(1)
    {
        printf("\nBINARY SEARCH TREE\n1.CREATE TREE:\n2.PREORDER\n3.INORDER:\n4.POSTORDER:\n5.SEARCH:\n6:DELETE:\n7.EXIT.\nOPTION:");
        scanf("%d",&opt);
        if(opt>6)
        {
            break;
        }
        switch(opt)
        {
            case 1:
                createTree(&p);
                break;
            case 2:
                printf("\nPREORDER:\n");
                preorder(p.rt);break;
            case 3:
                printf("\nINORDER:\n");
                inorder(p.rt);break;
            case 4:
                printf("\nPOSTORDER:\n");
                postorder(p.rt);break;
            case 5:
                printf("\nSEARCH VALUE:\n");
                scanf("%d",&sv);
                if(search(&p,sv)==0)
                {
                    printf("\nNOT FOUND.");
                }
                else
                {
                    printf("\nFOUND.");
                }

        }
        
    }
}