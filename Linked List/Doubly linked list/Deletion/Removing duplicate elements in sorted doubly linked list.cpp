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

void removingDuplicateElements(node *root) {
        node *p = root->next;
        node *q = root;
        while ( p != NULL ) {
                if ( p->data == q->data ) {
                        q->next = p->next;
                        if ( p->next )
                                p->next->prev = q;
                        delete(p);
                        p = q;
                }
                q = p;
                p = p->next;
        }
}

int main()
{
        node *root = NULL;
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 20);
        addElementLast(root, 30);
        addElementLast(root, 40);
        addElementLast(root, 40);

        cout << "Sorted doubly linked list : ";
        display(root);

        // Removing duplicate elements in sorted linked list
        removingDuplicateElements(root);
        cout << "After removing duplicate elements : ";
        display(root);

        return 0;
}
