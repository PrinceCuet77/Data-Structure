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

void addingTwoPolynomial(node *root1, node *root2, node *&sumOfRoot, node *&sumOfLast) {
        while ( root1 != NULL && root2 != NULL ) {
                if ( root1->exp > root2->exp ) {
                        makingPolynomial(sumOfRoot, sumOfLast, root1->coff, root1->exp);
                        root1 = root1->next;
                }
                else if ( root1->exp < root2->exp ) {
                        makingPolynomial(sumOfRoot, sumOfLast, root2->coff, root2->exp);
                        root2 = root2->next;
                }
                else {
                        makingPolynomial(sumOfRoot, sumOfLast, root1->coff+root2->coff, root1->exp);
                        root1 = root1->next;
                        root2 = root2->next;
                }
        }

        while ( root1 != NULL ) {
                makingPolynomial(sumOfRoot, sumOfLast, root1->coff, root1->exp);
                root1 = root1->next;
        }

        while ( root2 != NULL ) {
                makingPolynomial(sumOfRoot, sumOfLast, root2->coff, root2->exp);
                root2 = root2->next;
        }
}

int main()
{
        node *root1 = NULL, *last1 = NULL;

        printf("How many term in first polynomial : ");

        int term;
        scanf("%d", &term);

        printf("Enter co-efficients and exponents : \n");
        for ( int i = 0; i < term; i++ ) {
                int c, e;
                scanf("%d %d", &c, &e);

                makingPolynomial(root1, last1, c, e);
        }

        printf("First polynomial equation is : ");
        display(root1); // 4x^3 + 9x^2 + 6x^1 + 7x^0 or 4x^3 + 9x^2 + 6x + 7

        node *root2 = NULL, *last2 = NULL;

        printf("How many term in second polynomial : ");

        scanf("%d", &term);

        printf("Enter co-efficients and exponents : \n");
        for ( int i = 0; i < term; i++ ) {
                int c, e;
                scanf("%d %d", &c, &e);

                makingPolynomial(root2, last2, c, e);
        }

        printf("Second polynomial equation is : ");
        display(root2); // 7x^5 + 2x^4 + 3x^1 or 7x^5 + 2x^4 + 3x

        node *sumOfRoot = NULL, *sumOfLast = NULL;

        addingTwoPolynomial(root1, root2, sumOfRoot, sumOfLast);

        printf("New polynomial equation is : ");
        display(sumOfRoot);

        return 0;
}
