#include <bits/stdc++.h>
using namespace std;

struct BstNode {
        int data;
        BstNode *leftChild;
        BstNode *rightChild;
};

void createTree(BstNode *&root, int preorder[], int n) {
        stack < BstNode* > st;

        int i = 0;
        root = new BstNode();
        root->data = preorder[i++];
        root->leftChild = root->rightChild = NULL;

        BstNode *p = root;

        while ( i < n ) {
                if ( preorder[i] < p->data ) {
                        BstNode *t = new BstNode();
                        t->data = preorder[i++];
                        t->leftChild = t->rightChild = NULL;

                        p->leftChild = t;
                        st.push(p);
                        p = t;
                }
                else {
                        if ( preorder[i] > p->data ) {
                                BstNode *t = new BstNode();
                                t->data = preorder[i++];
                                t->leftChild = t->rightChild = NULL;

                                p->rightChild = t;
                                p = t;
                        }
                        else {
                                p = st.top();
                                st.pop();
                        }
                }
        }
}

void preorderTraversal(BstNode *root) {
        if ( root == NULL )
                return;

        printf("%d ", root->data);
        preorderTraversal(root->leftChild);
        preorderTraversal(root->rightChild);
}

/* Binary search tree :
                                30
                               /  \
                              20  40
                             /  \   \
                            10  25  50
                             \     /
                             15   45
*/

int main()
{
        int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
        int n = sizeof(preorder) / sizeof(preorder[0]);

        BstNode *root = NULL;

        createTree(root, preorder, n);

        printf("Pre-order traversal : ");
        preorderTraversal(root);
        printf("\n");

        return 0;
}
