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

void removeElementAtLast(node *&root) {
        node *p = root;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p->next != root );

        if ( p == q ) {
                delete(root);
                root = NULL;
                return;
        }

        q->next = p->next;
        p->next->prev = q;

        root = p->next;
        delete(p);
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

        // Removing element at last
        removeElementAtLast(root);
        cout << "Removing last element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementAtLast(root1, 100);

        cout << "Circular doubly linked list : ";
        display(root1);

        removeElementAtLast(root1);
        display(root1);

        return 0;
}
