#include <bits/stdc++.h>
using namespace std;

struct Stack {
        int n; // Size of stack
        int top; // Current position of last element in stack
        char *st; // Dynamic pointer array
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

void push(Stack *s, char x) {
        if ( isFull(s) ) {
                printf("Stack is full\n");
                return;
        }

        s->st[++s->top] = x;
}

char pop(Stack *s) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        return s->st[s->top--];
}

char stackTop(Stack *s) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        return s->st[s->top];
}

int precidence(char ch) { // Checking priority of operators
        if ( ch == '+' || ch == '-' )
                return 1;
        else if ( ch == '*' || ch == '/' )
                return 2;
}

bool isOperator(char ch) { // If exp[i] is an operator then return true else false
        if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' )
                return true;
        return false;
}

string infixToPostfix(Stack *s, string exp) {
        string res = "";
        for ( int i = 0; i < exp.length(); i++ ) {
                if ( isOperator(exp[i]) ) {
                        if ( isEmpty(s) )
                                push(s, exp[i]);
                        else {
                                int x1 = precidence(exp[i]);
                                int x2 = precidence(stackTop(s));
                                while ( x1 <= x2 ) {
                                        res += pop(s);
                                        if ( isEmpty(s) )
                                                break;
                                        x2 = precidence(stackTop(s));
                                }
                                push(s, exp[i]);
                        }
                }
                else
                        res += exp[i];
        }

        while ( !isEmpty(s) )
                res += pop(s);

        return res;
}

int main()
{
        string exp = "a+b*c-d/e";

        Stack *stk = new Stack();
        stk->n = exp.length();
        stk->top = -1;
        stk->st = new char[stk->n];

        printf("Infix notation is : %s\n", exp.c_str());
        printf("Postfix notation is : %s\n", infixToPostfix(stk, exp).c_str());

        return 0;
}
