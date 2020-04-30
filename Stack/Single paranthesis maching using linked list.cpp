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

bool isBalanced(node *&top, string exp) {
        for ( int i = 0; i < exp.length(); i++ ) {
                if ( exp[i] == '(' )
                        push(top, exp[i]);
                else if ( exp[i] == ')' ) {
                        if ( isEmpty(top) )
                                return false;
                        char c = pop(top);
                }
        }

        return isEmpty(top) ? true : false;
}

int main()
{
        string exp = "((A+B)*C)";
        string exp2 = "(A+B)*C)";

        node *top = NULL;

        if ( isBalanced(top, exp) )
                printf("Expression is balanced\n");
        else
                printf("Expression is not balanced\n");

        if ( isBalanced(top, exp2) )
                printf("Expression is balanced\n");
        else
                printf("Expression is not balanced\n");

        return 0;
}
