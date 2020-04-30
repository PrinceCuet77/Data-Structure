#include <bits/stdc++.h>
using namespace std;

struct BstNode {
        int data;
        BstNode *leftChild;
        BstNode *rightChild;
};

void createTree(BstNode *&root, int postorder[], int n) {
        stack < BstNode* > st;

        int i = n-1;
        root = new BstNode();
        root->data = postorder[i--];
        root->leftChild = root->rightChild = NULL;

        BstNode *p = root;

        while ( i >= 0 ) {
                if ( postorder[i] < p->data ) {
                        BstNode *t = new BstNode();
                        t->data = postorder[i--];
                        t->leftChild = t->rightChild = NULL;

                        p->leftChild = t;
                        st.push(p);
                        p = t;
                }
                else {
                        if ( postorder[i] > p->data ) {
                                BstNode *t = new BstNode();
                                t->data = postorder[i--];
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

void postorderTraversal(BstNode *root) {
        if ( root == NULL )
                return;

        postorderTraversal(root->leftChild);
        postorderTraversal(root->rightChild);
        printf("%d ", root->data);
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
        int postorder[] = {15, 10, 25, 20, 45, 50, 40, 30};
        int n = sizeof(postorder) / sizeof(postorder[0]);

        BstNode *root = NULL;

        createTree(root, postorder, n);

        printf("Post-order traversal : ");
        postorderTraversal(root);
        printf("\n");

        return 0;
}
