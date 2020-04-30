#include <bits/stdc++.h>
using namespace std;

struct Stack {
        int n; // Size of stack
        int top; // Current position of last element in stack
        int *st; // Dynamic pointer array
};

bool isEmpty(Stack *s) {
        if ( s->top == -1 )
                return true;
        return false;
}

bool isFull(Stack *s) {
        if ( s->top == s->n-1 )
                return true;
        return false;
}

void push(Stack *s, int x) {
        if ( isFull(s) ) {
                printf("Stack is full\n");
                return;
        }

        s->st[++s->top] = x;
}

int pop(Stack *s) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        return s->st[s->top--];
}

int peek(Stack *s, int index) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        if ( s->top - index + 1 < 0 ) {
                printf("Invalid position\n");
                return -1;
        }

        return s->st[s->top-index+1];
}

int stackTop(Stack *s) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        return s->st[s->top];
}

void display(Stack *s) {
        for ( int i = 0; i < s->n; i++ )
                printf("%d ", s->st[i]);
        printf("\n");
}

int main()
{
        Stack *stk = new Stack();
        stk->n = 5;
        stk->top = -1;
        stk->st = new int[stk->n];

        push(stk, 10);
        push(stk, 15);
        push(stk, 8);
        push(stk, 7);
        push(stk, 20);

        display(stk);

        printf("Last element %d is deleted\n", pop(stk));

        printf("The element of index 1 is : %d\n", peek(stk, 1));
        printf("The element of index 2 is : %d\n", peek(stk, 2));

        printf("Top element : %d\n", stackTop(stk));

        if ( isEmpty(stk) == true )
                printf("Stack is empty\n");
        else
                printf("Stack is not empty\n");

        if ( isFull(stk) == true )
                printf("Stack is full\n");
        else
                printf("Stack is not full\n");

        return 0;
}
