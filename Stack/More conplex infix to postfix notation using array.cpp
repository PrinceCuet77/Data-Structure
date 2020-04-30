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

int outStackPrecidence(char ch) {
        if ( ch == '+' || ch == '-' ) return 1;
        else if ( ch == '*' || ch == '/' ) return 3;
        else if ( ch == '^' ) return 6;
        else if ( ch == '(' ) return 7;
        else if ( ch == ')' ) return 0;
}

int inStackPrecidence(char ch) {
        if ( ch == '+' || ch == '-' ) return 2;
        else if ( ch == '*' || ch == '/' ) return 4;
        else if ( ch == '^' ) return 5;
        else if ( ch == '(' ) return 0;
}

bool isOperator(char ch) { // If exp[i] is an operator then return true else false
        if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '^' )
                return true;
        return false;
}

string infixToPostfix(Stack *s, string exp) {
        string res = "";
        for ( int i = 0; i < exp.length(); i++ ) {
                if ( isOperator(exp[i]) ) {
                        if ( isEmpty(s) ) {
                                push(s, exp[i]);
                        }
                        else {
                                int x1 = outStackPrecidence(exp[i]);
                                int x2 = inStackPrecidence(stackTop(s));
                                while ( x1 <= x2 ) {
                                        if ( exp[i] == ')' && stackTop(s) == '(' ) {
                                                char c = pop(s);
                                                break;
                                        }
                                        res += pop(s);
                                        x2 = inStackPrecidence(stackTop(s));
                                }
                                if ( exp[i] == ')' )
                                        continue;
                                else
                                        push(s, exp[i]);
                        }
                }
                else {
                        res += exp[i];
                }
        }

        while ( !isEmpty(s) )
                res += pop(s);

        return res;
}

int main()
{
        string exp = "((a+b)*c)-d^e^f";

        Stack *stk = new Stack();
        stk->n = exp.length();
        stk->top = -1;
        stk->st = new char[stk->n];

        printf("Infix notation is : %s\n", exp.c_str());
        printf("Postfix notation is : %s\n", infixToPostfix(stk, exp).c_str());

        return 0;
}
