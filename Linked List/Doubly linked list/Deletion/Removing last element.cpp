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

void removingLastElement(node *&root) {
        node *p = root;
        if ( root->prev == root->next ) {
                root = NULL;
                delete(p);
                return;
        }
        node *q = NULL;
        while ( p->next != NULL ) {
                q = p;
                p = p->next;
        }
        q->next = NULL;
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

        // Removing last element
        removingLastElement(root);
        cout << "After removing last element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementLast(root1, 100);

        cout << "Doubly linked list : ";
        display(root1);

        removingLastElement(root1);
        display(root1);

        return 0;
}
