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

                node *temp = new node(); // Creating new node
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

void addElementInNthPosition(node *&root, int data, int position) {
        if ( position == 0 ) {
                node *temp = new node(); // Creating new node
                temp->data = data;

                temp->prev = root->prev;
                temp->next = root;

                root->prev = temp;
                root = temp; // Updating root node
                return;
        }
        node *p = root;
        for ( int i = 0; i < position-2; i++ )
                p = p->next;

        node *temp = new node(); // Creating new node
        temp->data = data;

        temp->next = p->next;
        temp->prev = p;

        if ( p->next ) // If it is not last node
                p->next->prev = temp;
        p->next = temp;
}

int main()
{
        node *root = NULL;
        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 30);
        addElementLast(root, 40);
        addElementLast(root, 50);

        cout << "Doubly linked list : ";
        display(root);

        // Adding element in nth position
        addElementInNthPosition(root, 100, 4);
        cout << "Adding 100 in 4th position : ";
        display(root);

        addElementInNthPosition(root, 200, 0);
        cout << "Adding 200 in 0th position : ";
        display(root);

        addElementInNthPosition(root, 300, 8);
        cout << "Adding 300 in 8th position : ";
        display(root);

        return 0;
}
