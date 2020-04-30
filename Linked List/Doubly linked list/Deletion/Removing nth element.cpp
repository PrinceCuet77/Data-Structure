#include <bits/stdc++.h>
using namespace std;

struct node {
        node *prev;
        int data;
        node *next;
};

void addElementLast(node *&root, int data) {
        if ( root == NULL ) { // Adding first element
                root = new node();
                root->data = data;
                root->prev = NULL;
                root->next = NULL;
        } else {
                node *p = root;
                while ( p->next != NULL ) {
                        p = p->next;
                }

                node *temp = new node();
                temp->data = data;
                temp->prev = p;
                temp->next = NULL;

                p->next = temp;
        }
}

void display(node *root) {
        if ( root == NULL ) {
                cout << "Element does not exist in doubly linked list" << endl;
                return;
        }
        node *p = root;
        while ( p != NULL ) {
                cout << p->data << " ";
                p = p->next;
        }
        cout << endl;
}

void removingNthElement(node *&root, int position) {
        node *p = root;
        if ( position == 1 ) { // If I want to remove root node
                if ( root->prev == root->next ) // If I have only one node
                        root = NULL;
                else {
                        root = root->next;
                        root->prev = NULL;
                }
                delete(p);
                return;
        }
        node *q = NULL;
        for ( int i = 0; i < position-1; i++ ) {
                q = p;
                p = p->next;
        }
        q->next = p->next;
        if ( p->next ) // If I want to remove middle nodes
                p->next->prev = q;
        delete(p);
}

int main()
{
        node *root = NULL;
        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 30);
        addElementLast(root, 40);

        cout << "Doubly linked list : ";
        display(root);

        // Removing nth element
        removingNthElement(root, 3);
        cout << "After removing 3rd element : ";
        display(root);

        removingNthElement(root, 1);
        cout << "After removing 1st element : ";
        display(root);

        removingNthElement(root, 2);
        cout << "After removing last element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementLast(root1, 100);

        cout << "Doubly linked list : ";
        display(root1);

        removingNthElement(root1, 1);
        display(root1);

        return 0;
}
