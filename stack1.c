#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct stack {
    int top;
    int arr[M];
} STK;

void init(STK *t) {
    t->top = -1;
}

//PUSH FUNCTION
void push(STK *t, int d) {
    if (t->top == M - 1) {
        printf("\nOVERFLOW.");
    } else {
        t->top++;
        t->arr[t->top] = d;
    }
}

//POP FUNCTION
void pop(STK *t) {
    if (t->top == -1) {
        printf("\nUNDERFLOW");
    } else {
        t->top--;
    }
}

//DISPLAY FUNCTION
void display(STK *t) {
    int i = t->top;
    if (t->top == -1) {
        printf("EMPTY STACK.");
    } else {
        printf("\nSTACK DATA:\n");
        while (i >= 0) {
            printf("%4d", t->arr[i--]);
        }
    }
}

int main() {
    STK s;
    int opt, d;
    init(&s);

    while (1) {
        printf("\nMENU.\n1.PUSH.\n2.POP.\n3.DISPLAY.\n4.EXIT.\nOPTION:");
        scanf("%d", &opt);
        
        if (opt == 4) {
            break;
        }

        switch (opt) {
            case 1:
                printf("\nDATA:");
                scanf("%d", &d);
                push(&s, d);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            default:
                printf("\nInvalid Option\n");
        }
    }

    return 0;
}
