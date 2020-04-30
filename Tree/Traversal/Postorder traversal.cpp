#include <bits/stdc++.h>
using namespace std;

struct tree {
        int data;
        tree *leftChild, *rightChild;
        tree(int value) {
                data = value;
                leftChild = rightChild = NULL;
        }
};

void postOrderTraversal(tree *root) {
        if ( root == NULL )
                return;
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->data);
}

int main()
{
        tree *root = new tree(1);
        root->rightChild = new tree(2);
        root->rightChild->leftChild = new tree(3);
        root->rightChild->rightChild = new tree(4);
        root->rightChild->rightChild->leftChild = new tree(5);
        root->rightChild->rightChild->leftChild->rightChild = new tree(6);

        postOrderTraversal(root);
        printf("\n");

        return 0;
}
