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

bool isBalanced(Stack *s, string exp) {
        for ( int i = 0; i < exp.length(); i++ ) {
                if ( exp[i] == '(' )
                        push(s, exp[i]);
                else if ( exp[i] == ')' ) {
                        if ( isEmpty(s) )
                                return false;
                        char c = pop(s);
                }
        }

        return isEmpty(s) ? true : false;
}

int main()
{
        string exp = "((a+b)*c)";
        string exp2 = "(a+b)*c)";

        Stack *stk = new Stack();
        stk->n = exp.length();
        stk->top = -1;
        stk->st = new char[stk->n];

        if ( !isBalanced(stk, exp) )
                printf("Expression %s is not balanced\n", exp.c_str());
        else
                printf("Expression %s is balanced\n", exp.c_str());

        stk->n = exp2.length();
        stk->top = -1;
        stk->st = new char[stk->n];

        if ( !isBalanced(stk, exp2) )
                printf("Expression %s is not balanced\n", exp2.c_str());
        else
                printf("Expression %s is balanced\n", exp2.c_str());

        return 0;
}
