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

int stackTop(Stack *s) {
        if ( isEmpty(s) ) {
                printf("Stack is empty\n");
                return -1;
        }

        return s->st[s->top];
}

bool isOperator(char ch) { // If exp[i] is an operator then return true else false
        if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' )
                return true;
        return false;
}

bool isOperand(char ch) {
        if ( ch >= '0' && ch <= '9' )
                return true;
        return false;
}

int evaluation(int a, int b, char ch) {
        if ( ch == '+' ) return a+b;
        else if ( ch == '-' ) return a-b;
        else if ( ch == '*' ) return a*b;
        else if ( ch == '/' ) return a/b;
}

int evaluationOfPrefixNotation(Stack *s, string prefix) {
        for ( int i = prefix.length()-1; i >= 0; i-- ) {
                if ( isOperand(prefix[i]) )
                        push(s, prefix[i] - '0');
                else if ( isOperator(prefix[i]) ) {
                        int a = pop(s);
                        int b = pop(s);

                        push(s, evaluation(a, b, prefix[i]));
                }
        }

        return pop(s);
}

int main()
{
        string exp = "-+*35/624";
        printf("Prefix notation is : %s\n", exp.c_str());

        Stack *stk = new Stack();
        stk->n = exp.length();
        stk->top = -1;
        stk->st = new int[stk->n];

        int evaluationValue = evaluationOfPrefixNotation(stk, exp);
        printf("The evaluation value is : %d\n", evaluationValue);

        return 0;
}
