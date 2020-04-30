#include <bits/stdc++.h>
using namespace std;

struct node {
        int coff;
        int exp;
        node *next;
};

void makingPolynomial(node *&root, node *&last, int c, int e) {
        node *temp = new node();
        temp->coff = c;
        temp->exp = e;
        temp->next = NULL;

        if ( root == NULL )
                root = last = temp;
        else {
                last->next = temp;
                last = temp;
        }
}

void display(node *temp) {
        while ( temp != NULL ) {
                if ( temp->next == NULL )
                        printf("%dx^%d\n", temp->coff, temp->exp);
                else
                        printf("%dx^%d + ", temp->coff, temp->exp);
                temp = temp->next;
        }
}

double evaluationOfPolynomial(node *temp, int x) {
        double sum = 0;
        while ( temp != NULL ) {
                sum += temp->coff * pow(x, temp->exp);
                temp = temp->next;
        }

        return sum;
}

int main()
{
        node *root = NULL, *last = NULL;

        printf("How many term in polynomial : ");

        int term;
        scanf("%d", &term);

        printf("Enter co-efficients and exponents : \n");
        for ( int i = 0; i < term; i++ ) {
                int c, e;
                scanf("%d %d", &c, &e);

                makingPolynomial(root, last, c, e);
        }

        printf("Polynomial equation is : ");
        display(root); // 4x^3 + 9x^2 + 6x^1 + 7x^0 or 4x^3 + 9x^2 + 6x + 7

        double value = evaluationOfPolynomial(root, 2);
        printf("Evaluation of polynomial is : %f\n", value);

        return 0;
}
