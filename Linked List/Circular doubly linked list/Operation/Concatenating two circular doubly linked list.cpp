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

void concatenatingTwoCircularDoublyLinkedList(node *root1, node *&root2) {
        node *p = root1;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root1 );

        q->next = root2;
        root2->prev = q;

        node *p1 = root2;
        do {
                p1 = p1->next;
        } while ( p1->next != root2 );

        p1->next = p;
        p->prev = p1;

        root2 = NULL;
}

int main()
{
        node *root = NULL;
        addElementAtLast(root, 10);
        addElementAtLast(root, 20);
        addElementAtLast(root, 30);
        addElementAtLast(root, 40);
        addElementAtLast(root, 50);

        cout << "Circular doubly linked list(root) : ";
        display(root);

        node *root1 = NULL;
        addElementAtLast(root1, 1);
        addElementAtLast(root1, 2);
        addElementAtLast(root1, 3);
        addElementAtLast(root1, 4);

        cout << "Circular doubly linked list(root1) : ";
        display(root1);

        // Concatenating two circular doubly linked list
        concatenatingTwoCircularDoublyLinkedList(root, root1);
        cout << "After concatenating : ";
        display(root);
        display(root1);

        return 0;
}
