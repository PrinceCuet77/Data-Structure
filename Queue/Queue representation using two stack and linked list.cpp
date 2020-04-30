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

void enqueue(node *&s1, int value) {
        push(s1, value);
}

int dequeue(node *&s1, node *&s2) {
        int x = -1;

        if ( isEmpty(s2) ) {
                if ( isEmpty(s1) ) {
                        printf("Queue is empty\n");
                        return x;
                }

                while ( !isEmpty(s1) )
                        push(s2, pop(s1));
        }

        return pop(s2);
}

int main()
{
        node *s1 = NULL, *s2 = NULL;

        enqueue(s1, 6);
        enqueue(s1, 3);
        enqueue(s1, 9);
        enqueue(s1, 5);

        printf("Popped value : %d\n", dequeue(s1, s2));
        printf("Popped value : %d\n", dequeue(s1, s2));

        enqueue(s1, 4);
        enqueue(s1, 2);

        printf("Popped value : %d\n", dequeue(s1, s2));
        printf("Popped value : %d\n", dequeue(s1, s2));
        printf("Popped value : %d\n", dequeue(s1, s2));
        printf("Popped value : %d\n", dequeue(s1, s2));

        int x = dequeue(s1, s2);
        if ( x != -1 )
                printf("Popped value : %d\n", x);

        return 0;
}
