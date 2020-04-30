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

bool Search(BstNode *root, int key) {
        if ( root == NULL )
                return false;

        if ( root->data == key ) // Found
                return true;
        else if ( root->data > key )
                return Search(root->leftChild, key); // Searching to left subtree
        else
                return Search(root->rightChild, key); // Searching to right subtree
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

        if ( Search(root, 5) )
                printf("key 5 is found\n");
        else
                printf("Key 5 is not found\n");

        if ( Search(root, 33) )
                printf("Key 33 is found\n");
        else
                printf("key 33 is not found\n");

        return 0;
}
