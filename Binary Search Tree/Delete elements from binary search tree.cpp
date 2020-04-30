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
        while ( root->leftChild != NULL )
                root = root->leftChild;

        return root;
}

BstNode* Delete(BstNode *root, int data) {
        if ( root == NULL )
                return root;

        if ( data < root->data )
                root->leftChild = Delete(root->leftChild, data);
        else if ( data > root->data )
                root->rightChild = Delete(root->rightChild, data);
        else {
                // Case 1: No Child or leaf node
                if ( root->leftChild == NULL && root->rightChild == NULL ) {
                        delete(root);
                        root = NULL;
                }
                else if ( root->leftChild == NULL ) { // Case 2: Has 1 child or has left child
                        BstNode *temp = root;
                        root = root->rightChild;
                        delete(temp);
                }
                else if ( root->rightChild == NULL ) { // Case 2: Has 1 child or has right child
                        BstNode *temp = root;
                        root = root->leftChild;
                        delete(temp);
                }
                else { // Case 3: Has 2 children
                        BstNode *temp = findMin(root->rightChild); // Finding min value in right subtree of given node
                        root->data = temp->data; // Replace given node by min value
                        root->rightChild = Delete(root->rightChild, temp->data); // Deleting min value to go right subtree
                }
        }

        return root;
}

void levelOrderTraversal(BstNode *root) {
        queue < BstNode* > q; // Using queue data structure
        q.push(root);

        while ( !q.empty() ) {
                BstNode *t = q.front();
                q.pop();

                printf("%d ", t->data);

                if ( t->leftChild )
                        q.push(t->leftChild);

                if ( t->rightChild )
                        q.push(t->rightChild);
        }
        printf("\n");
}

/*      Binary search tree :
              15                                   15                                  15                                      15
             /  \                                 /  \                                /  \                                    /  \
            /    \                               /    \                              /    \                                  /    \
           /      \                             /      \                            /      \                                /      \
          10       20    After deleting 6    10        20    After deleting 12     10       20     After deleting 20       10       25
         /  \     /  \  ----------------->  /  \      /  \  ------------------>   /  \     /  \   ------------------>     /  \     /  \
        /    \   /    \                    /    \    /    \                      /    \   /    \                         /    \   /    \
       8     12 17    25                  8     12  17    25                    8     11 17    25                       8     11 17    27
      /      /  /       \                       /   /       \                           /        \                              /
     /      /  /         \                     /   /         \                         /          \                            /
    6     11  16         27                   11  16         27                       16          27                          16

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

        // Print all the element
        printf("Binary search tree : ");
        levelOrderTraversal(root);

        printf("After deleting 6(no child) : ");
        root = Delete(root, 6);
        levelOrderTraversal(root);

        printf("After deleting 12(1 child) : ");
        root = Delete(root, 12);
        levelOrderTraversal(root);

        printf("After deleting 20(2 children) : ");
        root = Delete(root, 20);
        levelOrderTraversal(root);

        return 0;
}
