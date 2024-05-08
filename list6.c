#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct slist {
    NODE* st;
    int cnt;
    int tot;
} SLIST;

void init(SLIST* t) {
    t->st = NULL;
    t->cnt = 0;
    t->tot = 0;
}

NODE* createNode(int d) {
    NODE* a = (NODE*)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

NODE* getLastNode(SLIST* t) {
    NODE* a = t->st;
    while (a != NULL) {
        a = a->next;
    }
    return a;
}

void addE(SLIST* t, int d) {
    NODE* a = createNode(d);
    NODE* b;
    if (t->st == NULL)
        t->st = a;
    else {
        b = getLastNode(t);
        b->next = a;
    }
    t->cnt++;
    t->tot += d;
}

void addB(SLIST* t, int d) {
    NODE* a = createNode(d);
    a->next = t->st;
    t->st = a;
    t->cnt++;
    t->tot += d;
}

void display(SLIST* t) {
    NODE* a = t->st;
    if (t->st == NULL)
        printf("\nEmpty List");
    else {
        printf("\n Data\n");
        while (a != NULL) {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

void Odisplay(SLIST* t) {
    NODE* a = t->st;
    if (t->st == NULL)
        printf("\n Empty List\n");
    else {
        printf("\n Odd Data");
        while (a != NULL) {
            if (a->data % 2 == 1)
                printf("%4d", a->data);
            a = a->next;
        }
    }
}

void Edisplay(SLIST* t) {
    NODE* a = t->st;
    if (t->st == NULL)
        printf("\n Empty List");
    else {
        printf("\n Data\n");
        while (a != NULL) {
            if (a->data % 2 == 0)
                printf("%4d", a->data);
            a = a->next;
        }
    }
}

int Ocount(SLIST* t) {
    int cnt = 0;
    NODE* a = t->st;
    while (a != NULL) {
        cnt = cnt + (a->data % 2);
        a = a->next;
    }
    return cnt;
}

int Ecount(SLIST* t) {
    int cnt = 0;
    NODE* a = t->st;
    while (a != NULL) {
        cnt = cnt + (a->data % 2 == 0);
        a = a->next;
    }
    return cnt;
}

int findMax(SLIST* t) {
    NODE* a = t->st;
    int max = a->data;
    for (a = a->next; a != NULL; a = a->next) {
        if (a->data > max)
            max = a->data;
    }
    return max;
}

int findMin(SLIST* t) {
    NODE* a = t->st;
    int min = a->data;
    for (a = a->next; a != NULL; a = a->next) {
        if (a->data < min)
            min = a->data;
    }
    return min;
}

void delFirst(SLIST* t) {
    NODE* a = t->st;
    if (t->st == NULL) // empty list
        return;
    if (a->next == NULL) // only one node
        t->st = NULL;
    else
        t->st = a->next;
    t->cnt--;
    t->tot = t->tot - a->data;
    free(a);
}

void delLast(SLIST* t) {
    NODE* a = t->st;
    NODE* b = NULL; // Fix: Declare 'b'
    if (t->st == NULL) // empty list
        return;
    if (a->next == NULL) // only one node
        t->st = NULL;
    else {
        while (a->next != NULL) {
            b = a;
            a = a->next;
        }
        b->next = NULL;
    }
    t->cnt--;
    t->tot = t->tot - a->data;
    free(a);
}

void delinode(SLIST* t, int pos) {
    int i = 1;
    NODE* a = t->st;
    NODE* b, * c;
    if (t->st == NULL) // empty list
        return;
    if (t->cnt == 0 || pos < 1 || pos > t->cnt)
        return;
    if (pos == 1)
        delFirst(t);
    else {
        if (pos == t->cnt)
            delLast(t);
        else {
            while (i < pos) {
                b = a;
                a = a->next;
                i++;
            }
            c = a->next;
            b->next = c;
            t->cnt--;
            t->tot = t->tot - a->data;
            free(a);
        }
    }
}

int main() {
    SLIST p;
    int opt, d, pos;

    init(&p);

    while (1) {
        printf("\n MENU\n 1.Add new node at end\n 2.add new node at begin\n 3.Display\n4.Count\n5.Sum\n 6.Odd values display\n7.even values display\n8.count odd nodes\n9.count even nodes\n10.maximum\n11.minimum\n12.Delete First node.\n13.Delete last node.\n14.Delete any node.\n OPTION: ");
        scanf("%d", &opt);
        if (opt > 11)
            break;

        switch (opt) {
            case 1:
                printf("\n Data: ");
                scanf("%d", &d);
                addE(&p, d);
                break;

            case 2:
                printf("\n Data: ");
                scanf("%d", &d);
                addB(&p, d);
                break;

            case 3:
                display(&p);
                break;

            case 4:
                printf("\n Node count:%d", p.cnt);
                break;

            case 5:
                printf("\n Sum:%d", p.tot);
                break;

            case 6:
                Odisplay(&p);
                break;

            case 7:
                Edisplay(&p);
                break;

            case 8:
                printf("\n Odd data count: %d", Ocount(&p));
                break;

            case 9:
                printf("\n Even data count: %d", Ecount(&p));
                break;

            case 10:
                if (p.st == NULL)
                    printf("\n empty list");
                else
                    printf("\n Maximum: %d", findMax(&p));
                break;

            case 11:
                if (p.st == NULL)
                    printf("\n Empty List");
                else
                    printf("\n Minimum: %d", findMin(&p));
                break;

            case 12:
                delFirst(&p);
                break;

            case 13:
                delLast(&p);
                break;

            case 14:
                printf("Enter node position to delete: ");
                scanf("%d", &pos);
                delinode(&p, pos);
                break;
        }
    }

    return 0;
}
