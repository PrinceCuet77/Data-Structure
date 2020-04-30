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

/*  Tree visualization:
                                8
                               / \
                              3   5
                             /   / \
                            12  10  6
                             \     /
                              4   2
                             / \
                            9   7
*/

int totalNodes(tree *root) {
        if ( root == NULL )
                return 0;
        int x = totalNodes(root->leftChild);
        int y = totalNodes(root->rightChild);
        return x + y + 1;
}

int main()
{
        tree *root = new tree(8);
        root->leftChild = new tree(3);
        root->leftChild->leftChild = new tree(12);
        root->leftChild->leftChild->rightChild = new tree(4);
        root->leftChild->leftChild->rightChild->leftChild = new tree(9);
        root->leftChild->leftChild->rightChild->rightChild = new tree(7);
        root->rightChild = new tree(5);
        root->rightChild->leftChild = new tree(10);
        root->rightChild->rightChild = new tree(6);
        root->rightChild->rightChild->leftChild = new tree(2);

        printf("Total nodes are : %d\n", totalNodes(root));

        return 0;
}
