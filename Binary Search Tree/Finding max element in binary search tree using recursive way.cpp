#include <bits/stdc++.h>
using namespace std;

struct BstNode {
        int data;
        BstNode *leftChild;
        BstNode *rightChild;
};

BstNode* Insert(BstNode *root, int data) {
        if ( root == NULL ) { // Nothing in binary search tree
                root = new BstNode();
                root->data = data;
                root->leftChild = root->rightChild = NULL;
                return root;
        }

        if ( data <= root->data )
                root->leftChild = Insert(root->leftChild, data);
        else
                root->rightChild = Insert(root->rightChild, data);

        return root;
}

int findingMax(BstNode *root) {
        if ( root == NULL ) // Base condition
                return 0;

        if ( root->leftChild == NULL && root->rightChild == NULL ) // Leaf node should return whatever the data it has
                return root->data;

        int leftMax = findingMax(root->leftChild); // Maximum value got from left subtree
        int rightMax = findingMax(root->rightChild); // Maximum value got from right subtree

        return max(leftMax, rightMax);
}

/* Binary search tree :

                                20
                               /  \
                             10    30
                            / \   /  \
                           5  15 25  35

*/

int main()
{
        BstNode *root = NULL;

        root = Insert(root, 20);
        root = Insert(root, 10);
        root = Insert(root, 30);
        root = Insert(root, 5);
        root = Insert(root, 15);
        root = Insert(root, 35);
        root = Insert(root, 25);

        printf("Maximum in binary search tree : %d\n", findingMax(root));

        return 0;
}
