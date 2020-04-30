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

 void addingTwoSparseMatrix(node *root1, node *root2, node *&sumOfRoot, node *&sumOfLast) {
        while ( root1 != NULL && root2 != NULL ) {
                if ( root1->row < root2->row ) {
                        makingSparseMatrix(sumOfRoot, sumOfLast, root1->row, root1->col, root1->val);
                        root1 = root1->next;
                }
                else if ( root1->row > root2->row ) {
                        makingSparseMatrix(sumOfRoot, sumOfLast, root2->row, root2->col, root2->val);
                        root2 = root2->next;
                }
                else if ( root1->row == root2->row ) {
                        if ( root1->col < root2->col ) {
                                makingSparseMatrix(sumOfRoot, sumOfLast, root1->row, root1->col, root1->val);
                                root1 = root1->next;
                        }
                        else if ( root1->col > root2->col ) {
                                makingSparseMatrix(sumOfRoot, sumOfLast, root2->row, root2->col, root2->val);
                                root2 = root2->next;
                        }
                        else {
                                makingSparseMatrix(sumOfRoot, sumOfLast, root1->row, root1->col, root1->val+root2->val);
                                root1 = root1->next;
                                root2 = root2->next;
                        }
                }
        }

        while ( root1 != NULL ) {
                makingSparseMatrix(sumOfRoot, sumOfLast, root1->row, root1->col, root1->val);
                root1 = root1->next;
        }

        while ( root2 != NULL ) {
                makingSparseMatrix(sumOfRoot, sumOfLast, root2->row, root2->col, root2->val);
                root2 = root2->next;
        }
 }

int main()
{
        int mat1[4][5] =
        {
                {0 , 0 , 3 , 0 , 4 },
                {0 , 0 , 5 , 7 , 0 },
                {0 , 0 , 0 , 0 , 0 },
                {0 , 2 , 6 , 0 , 0 }
        };

        int mat2[4][5] =
        {
                {0 , 0 , 5 , 0 , 0 },
                {0 , 0 , 0 , 1 , 0 },
                {0 , 7 , 0 , 0 , 0 },
                {2 , 0 , 0 , 8 , 0 }
        };

        node *root1 = NULL, *last1 = NULL;
        for ( int i = 0; i < 4; i++ ) {
                for ( int j = 0; j < 5; j++ ) {
                        if ( mat1[i][j] != 0 )
                                makingSparseMatrix(root1, last1, i, j, mat1[i][j]);
                }
        }

        printf("Sparse matrix 1 : \n");
        displaySparseMatrix(root1, 4, 5);

        node *root2 = NULL, *last2 = NULL;
        for ( int i = 0; i < 4; i++ ) {
                for ( int j = 0; j < 5; j++ ) {
                        if ( mat2[i][j] != 0 )
                                makingSparseMatrix(root2, last2, i, j, mat2[i][j]);
                }
        }

        printf("Sparse matrix 2 : \n");
        displaySparseMatrix(root2, 4, 5);

        node *sumOfRoot = NULL, *sumOfLast = NULL;

        addingTwoSparseMatrix(root1, root2, sumOfRoot, sumOfLast);

        printf("Sum of sparse matrix : \n");
        displaySparseMatrix(sumOfRoot, 4, 5);

        return 0;
}
