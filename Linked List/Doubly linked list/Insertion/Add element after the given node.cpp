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

void addElementAfterGivenNode(node *root, int givenNode, int data) {
        node *p = root;
        while ( p->data != givenNode ) {
                //cout << p->data << endl;
                p = p->next;
        }

        node *temp = new node(); // Creating new node
        temp->data = data;

        temp->next = p->next;
        temp->prev = p;

        if ( p->next ) // If given node is not last node
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

        // Adding element after given node
        addElementAfterGivenNode(root, 30, 100);
        cout << "Adding 100 after 30 : ";
        display(root);

        addElementAfterGivenNode(root, 50, 200);
        cout << "Adding 200 after 50 : ";
        display(root);

        return 0;
}
