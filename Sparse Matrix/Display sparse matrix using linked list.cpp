#include <bits/stdc++.h>
using namespace std;

struct node {
        int row;
        int col;
        int val;
        node *next;
};

 void makingSparseMatrix(node *&root, node *&last, int r, int c, int v) {
        node *temp = new node();
        temp->row = r;
        temp->col = c;
        temp->val = v;
        temp->next = NULL;

        if ( root == NULL )
                root = last = temp;
        else {
                last->next = temp;
                last = temp;
        }
 }

 void displaySparseMatrix(node *temp, int r, int c) {
        for ( int i = 0; i < r; i++ ) {
                for ( int j = 0; j < c; j++ ) {
                        if ( temp != NULL ) {
                                if ( i == temp->row && j == temp->col ) {
                                        printf("%d ", temp->val);
                                        temp = temp->next;
                                }
                                else
                                        printf("0 ");
                        }
                        else
                                printf("0 ");
                }
                printf("\n");
        }
 }

int main()
{
        int mat[4][5] =
        {
                {0 , 0 , 3 , 0 , 4 },
                {0 , 0 , 5 , 7 , 0 },
                {0 , 0 , 0 , 0 , 0 },
                {0 , 2 , 6 , 0 , 0 }
        };

        node *root = NULL, *last = NULL;
        for ( int i = 0; i < 4; i++ ) {
                for ( int j = 0; j < 5; j++ ) {
                        if ( mat[i][j] != 0 )
                                makingSparseMatrix(root, last, i, j, mat[i][j]);
                }
        }

        printf("Sparse matrix : \n");
        displaySparseMatrix(root, 4, 5);

        return 0;
}
