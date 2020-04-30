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
                            25
                           /  \
                         10    28
                        / \    / \
                       5  20  27  30
*/

int main()
{
        root = Insert(root, 10);
        root = Insert(root, 20);
        root = Insert(root, 30);
        root = Insert(root, 25);
        root = Insert(root, 28);
        root = Insert(root, 27);
        root = Insert(root, 5);

        printf("Level order traversal of AVL tree : ");
        levelOrderTraversal(root);

        return 0;
}
