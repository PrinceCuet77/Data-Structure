#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *prev;
        node *next;
};

void addElementAtLast(node *&root, int data) {
        if ( root == NULL ) {
                root = new node();
                root->data = data;
                root->prev = root->next = root;
                return;
        }
        node *temp = new node(); // Creating new node
        temp->data = data;

        node *p = root;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root );

        q->next = p->prev = temp;
        temp->next = p;
        temp->prev = q;
}

void display(node *root) {
        if ( root == NULL ) {
                cout << "Element does not exist in circular linked list" << endl;
                return;
        }
        node *p = root;
        do {
                cout << p->data << " ";
                p = p->next;
        } while ( p != root );
        cout << endl;
}

void addElement(node *&root, int data) {
        node *temp = new node();
        temp->data = data;

        node *p = root;
        if ( root->data > data ) {
                temp->next = root;
                root->prev = temp;
                do {
                        p = p->next;
                } while ( p->next != root );

                p->next = temp;
                temp->prev = p;

                root = temp;
                return;
        }
        node *q = NULL;
        do {
                if ( p->data > data )
                        break;
                q = p;
                p = p->next;
        } while ( p != root );

        temp->next = p;
        temp->prev = q;

        p->prev = q->next = temp;
}

int main()
{
        node *root = NULL;
        addElementAtLast(root, 10);
        addElementAtLast(root, 20);
        addElementAtLast(root, 30);
        addElementAtLast(root, 40);
        addElementAtLast(root, 50);

        cout << "Circular doubly linked list : ";
        display(root);

        // Adding element in sorted circular linked list
        addElement(root, 5);
        cout << "Adding 5 : ";
        display(root);

        addElement(root, 25);
        cout << "Adding 25 : ";
        display(root);

        addElement(root, 300);
        cout << "Adding 300 : ";
        display(root);

        return 0;
}
