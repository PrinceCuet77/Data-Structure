#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

bool isEmpty(node *top) {
        // Alternative solution : return top ? false : true;

        if ( top == NULL )
                return true;
        return false;
}

bool isFull() {
        node *temp = new node();
        bool result = temp ? false : true;
        delete(temp);
        return result;
}

void push(node *&top, int x) {
        if ( isFull() == true ) {
                printf("Stack is full\n");
                return;
        }

        if ( top == NULL ) {
                top = new node();
                top->data = x;
                top->next = NULL;
        } else {
                node *temp = new node();
                temp->data = x;
                temp->next = top;

                top = temp;
        }
}

void display(node *temp) {
        if ( isEmpty(temp) ) {
                printf("Stack is empty\n");
                return;
        }

        while ( temp != NULL ) {
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("\n");
}

int pop(node *&top) {
        int x = -1;
        if ( isEmpty(top) ) {
                printf("Stack is empty\n");
                return x;
        }

        node *temp = top;
        x = temp->data;
        top = temp->next;
        delete(temp);

        return x;
}

int peek(node *temp, int pos) {
        if ( isEmpty(temp) ) {
                printf("Stack is empty\n");
                return -1;
        }

        if ( pos <= 0 ) {
                printf("Invalid position\n");
                return -1;
        }

        int cnt = 1;
        while ( temp != NULL ) {
                if ( cnt == pos )
                        return temp->data;
                cnt++;
                temp = temp->next;
        }
}

int stackTop(node *temp) {
        return temp->data;
}

int main()
{
        node *top = NULL;

        if ( isEmpty(top) == true )
                printf("Stack is empty\n");
        else
                printf("Stack is not empty\n");

        push(top, 10);
        push(top, 15);
        push(top, 8);
        push(top, 3);

        display(top);

        printf("Top of the stack is : %d\n", stackTop(top));

        printf("3rd element of the stack is : %d\n", peek(top, 3));

        printf("Popped element : %d\n", pop(top));

        printf("Top of the stack is : %d\n", stackTop(top));

        return 0;
}
