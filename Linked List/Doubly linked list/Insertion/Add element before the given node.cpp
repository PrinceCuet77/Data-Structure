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

void addElementBeforeGivenNode(node *&root, int givenNode, int data) {
        if ( root->data == givenNode ) {
                node *temp = new node(); // Creating new node
                temp->data = data;

                temp->prev = root->prev;
                temp->next = root;

                root->prev = temp;
                root = temp; // Updating root node
                return;
        }
        node *p = root;
        node *q = NULL;
        while ( p->data != givenNode ) {
                q = p;
                p = p->next;
        }

        node *temp = new node(); // Creating new node
        temp->data = data;

        temp->next = p;
        temp->prev = q;

        q->next = p->prev = temp;
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

        // Adding element before given node
        addElementBeforeGivenNode(root, 30, 100);
        cout << "Adding 100 before 30 : ";
        display(root);

        addElementBeforeGivenNode(root, 10, 200);
        cout << "Adding 200 before 10 : ";
        display(root);

        return 0;
}
