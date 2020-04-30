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

BstNode* findMin(BstNode *root) {
        if ( root == NULL )
                return root;

        while ( root->leftChild != NULL )
                root = root->leftChild;

        return root;
}

BstNode* findNode(BstNode *root, int data) {
        if ( root == NULL )
                return root;

        if ( root->data == data )
                return root;
        else if ( root->data > data )
                return findNode(root->leftChild, data);
        else
                return findNode(root->rightChild, data);
}

BstNode* getSuccessor(BstNode *root, int data) { // To find In-order Successor in a BST
        BstNode *current = findNode(root, data);

        if ( current == NULL )
                return current;

        if ( current->rightChild != NULL ) // Case 1: Node has right subtree
                return findMin(current->rightChild);
        else { // Case 2: Node has no right subtree
                BstNode *successor = NULL;
                BstNode *ancestor = root;

                while ( ancestor != current ) {
                        if ( ancestor->data > current->data ) {
                                successor = ancestor; // So far this is the deepest node for which current node is in left
                                ancestor = ancestor->leftChild;
                        }
                        else
                                ancestor = ancestor->rightChild;
                }

                return successor;
        }
}

/*      Binary search tree :
                                                 15
                                               /   \
                                              /     \
                                             /       \
                                           10         20
                                          /  \       /  \
                                         /    \     /    \
                                        8     12   17    25
                                       /     /    /        \
                                      /     /    /          \
                                     6     11   16          27

*/

int main()
{
        BstNode *root = NULL;

        root = Insert(root, 15);
        root = Insert(root, 10);
        root = Insert(root, 20);
        root = Insert(root, 8);
        root = Insert(root, 6);
        root = Insert(root, 12);
        root = Insert(root, 11);
        root = Insert(root, 17);
        root = Insert(root, 16);
        root = Insert(root, 25);
        root = Insert(root, 27);

        BstNode *t = getSuccessor(root, 6);
        printf("8 successor is : %d\n", t->data);

        t = getSuccessor(root, 12);
        printf("12 successor is : %d\n", t->data);

        t = getSuccessor(root, 10);
        printf("10 successor is : %d\n", t->data);

        return 0;
}
