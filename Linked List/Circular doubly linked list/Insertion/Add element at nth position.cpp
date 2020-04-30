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

void addElementAtNthPosition(node *&root, int data, int position) {
        node *temp = new node();
        temp->data = data;

        node *p = root;
        if ( position == 1 ) {
                temp->next = root;
                root->prev = temp;

                do {
                        p = p->next;
                } while ( p->next != root );

                temp->prev = p;
                p->next = temp;

                root = temp;
                return;
        }
        node *q = NULL;
        for ( int i = 0; i < position-1; i++ ) {
                q = p;
                p = p->next;
        }

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

        // Adding element at nth position
        addElementAtNthPosition(root, 100, 3);
        cout << "Adding 100 in 3rd position : ";
        display(root);

        addElementAtNthPosition(root, 200, 7);
        cout << "Adding 200 in 7th position : ";
        display(root);

        addElementAtNthPosition(root, 300, 1);
        cout << "Adding 300 in 1st position : ";
        display(root);

        return 0;
}
