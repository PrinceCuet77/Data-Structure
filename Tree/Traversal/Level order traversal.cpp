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

void levelOrderTraversal(tree *root) {
        queue < tree* > q;
        q.push(root);
        while ( !q.empty() ) {
                root = q.front();
                printf("%d ", root->data);
                q.pop();
                if ( root->leftChild )
                        q.push(root->leftChild);
                if ( root->rightChild )
                        q.push(root->rightChild);
        }
}

int main()
{
        tree *root = new tree(1);
        root->rightChild = new tree(2);
        root->rightChild->leftChild = new tree(3);
        root->rightChild->rightChild = new tree(4);
        root->rightChild->rightChild->leftChild = new tree(5);
        root->rightChild->rightChild->leftChild->rightChild = new tree(6);

        levelOrderTraversal(root);
        printf("\n");

        return 0;
}
