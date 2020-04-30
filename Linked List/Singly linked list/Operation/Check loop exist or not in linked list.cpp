#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void addNodeLast( node *&root, int data ) {
        if ( root == NULL ) { // Inserting first element
                root = new node();
                root->data = data;
                root->next = NULL;
        } else {
                node *current = root;
                while ( current->next != NULL ) // Traversing before last element
                        current = current->next;

                node *temp = new node(); // Taking place for new element
                temp->data = data;
                temp->next = NULL; // It will be last element so taking null

                current->next = temp;
        }
}

bool isLoop(node *p) {
        node *q;
        q = p;
        do {
                p = p->next; // Tortoise and hare technique
                q = q->next;
                q = q ? q->next : q;
        } while ( p && q && p != q );
        return p == q ? true : false;
}

int main()
{
        node *root = NULL;

        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);
        addNodeLast(root, 50);

        node *t1, *t2;
        t1 = root->next->next;
        t2 = root->next->next->next->next;
        t2->next = t1;

        if ( isLoop(root) )
                cout << "Loop exist" << endl;
        else
                cout << "No loop exist" << endl;

        return 0;
}

