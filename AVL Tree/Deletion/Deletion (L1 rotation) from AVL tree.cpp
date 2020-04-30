#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        int height;
        node *leftChild;
        node *rightChild;
} *root = NULL;

int heightOfTree(node *p) {
        int leftHeight = p && p->leftChild ? p->leftChild->height : 0;
        int rightHeight = p && p->rightChild ? p->rightChild->height : 0;

        return max(leftHeight, rightHeight) + 1;
}

int balanceFactor(node *p) {
        int leftHeight = p && p->leftChild ? p->leftChild->height : 0;
        int rightHeight = p && p->rightChild ? p->rightChild->height : 0;

        return leftHeight - rightHeight;
}

node* LLRotation(node *p) {
        node *pl = p->leftChild;
        node *plr = pl->rightChild;

        pl->rightChild = p;
        p->leftChild = plr;

        p->height = heightOfTree(p);
        pl->height = heightOfTree(pl);

        if ( root == p )
                root = pl;

        return pl;
}

node* LRRotation(node* p) {
        node *pl = p->leftChild;
        node *plr = pl->rightChild;

        p->leftChild = plr->rightChild;
        pl->rightChild = plr->leftChild;

        plr->leftChild = pl;
        plr->rightChild = p;

        p->height = heightOfTree(p);
        pl->height = heightOfTree(pl);
        plr->height = heightOfTree(plr);

        if ( root = p )
                root = plr;

        return plr;
}

node* RRRotation(node* p) {
        node *pr = p->rightChild;
        node *prl = pr->leftChild;

        p->rightChild = prl;
        pr->leftChild = p;

        p->height = heightOfTree(p);
        pr->height = heightOfTree(pr);

        if ( root == p )
                return pr;

        return pr;
}

node* RLRotation(node* p) {
        node *pr = p->rightChild;
        node *prl = pr->leftChild;

        pr->leftChild = prl->rightChild;
        p->rightChild = prl->leftChild;

        prl->leftChild = p;
        prl->rightChild = pr;

        p->height = heightOfTree(p);
        pr->height = heightOfTree(pr);
        prl->height = heightOfTree(prl);

        if ( root == p )
                return prl;

        return prl;
}

node* Insert(node *p, int data) {
        if ( p == NULL ) {
                p = new node();
                p->data = data;
                p->height = 1;
                p->leftChild = p->rightChild;
                return p;
        }

        if ( p->data >= data )
                p->leftChild = Insert(p->leftChild, data);
        else if ( p->data < data )
                p->rightChild = Insert(p->rightChild, data);

        p->height = heightOfTree(p);

        if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) == 1 )
                return LLRotation(p);
        else if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) == -1 )
                return LRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) == -1 )
                return RRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) == 1 )
                return RLRotation(p);

        return p;
}

node* findMin(node *p) {
        while ( p->leftChild != NULL ) // Traverse the left most child to find min
                p = p->leftChild;

        return p;
}

node* Delete(node *p, int data) {
        if ( p == NULL )
                return p;

        if ( data < p->data )
                p->leftChild = Delete(p->leftChild, data);
        else if ( data > p->data )
                p->rightChild = Delete(p->rightChild, data);
        else {
                // Case 1: No Child or leaf node
                if ( p->leftChild == NULL && p->rightChild == NULL ) {
                        delete(p);
                        p = NULL;
                }
                else if ( p->leftChild == NULL ) { // Case 2: Has 1 child or has left child
                        node *temp = p;
                        p = p->rightChild;
                        delete(temp);
                }
                else if ( p->rightChild == NULL ) { // Case 2: Has 1 child or has right child
                        node *temp = p;
                        p = p->leftChild;
                        delete(temp);
                }
                else { // Case 3: Has 2 children
                        node *temp = findMin(p->rightChild); // Finding min value in right subtree of given node
                        p->data = temp->data; // Replace given node by min value
                        p->rightChild = Delete(p->rightChild, temp->data); // Deleting min value to go right subtree
                }
        }

        if ( p == NULL ) // Special case
                return p;

        p->height = heightOfTree(p); // Count the height

        if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) >= 0 ) // L1 or L0 rotation
                return LLRotation(p);
        else if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) == -1 ) // L-1 rotation
                return LRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) <= 0 ) // R1 or R0 rotation
                return RRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) == 1 ) // R-1 rotation
                return RLRotation(p);

        return p;
}

void levelOrderTraversal(node *root) {
        queue < node* > q;
        q.push(root);

        while ( !q.empty() ) {
                node *t = q.front();
                q.pop();

                printf("%d ", t->data);

                if ( t->leftChild )
                        q.push(t->leftChild);

                if ( t->rightChild )
                        q.push(t->rightChild);
        }
        printf("\n");
}

/* AVL tree :
                            30                                       30                             20
                           /  \          After deleting 40          /        L1 rotation           /  \
                         20    40       ------------------>        20       ------------>         10  30
                        /                                         /
                       10                                        10
*/

int main()
{
        root = Insert(root, 30);
        root = Insert(root, 20);
        root = Insert(root, 40);
        root = Insert(root, 10);

        printf("Level order traversal of AVL tree : ");
        levelOrderTraversal(root);

        root = Delete(root, 40);

        printf("After deleting 40(L1 rotation) : ");
        levelOrderTraversal(root);

        return 0;
}
