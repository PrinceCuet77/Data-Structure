#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void addElementLast(node *&root, int data) {
        if ( root == NULL ) { // Adding very first element which is called root
                root = new node();
                root->data = data;
                root->next = root;
        } else {
                node *temp = new node();
                temp->data = data;

                node *p = root;
                node *q = NULL;
                do {
                        q = p;
                        p = p->next;
                } while ( p != root );

                if ( p == q ) { // When circular linked list has only one element
                        temp->next = p;
                        p->next = temp;
                } else {
                        q->next = temp;
                        temp->next = p;
                }
        }
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

void removeFirstElement(node *&root) {
        node *p = root;
        node *q = NULL;
        if ( p->next == root ) { // If it has only one element
                root = NULL;
                delete(p);
                return;
        }
        do {
                q = p;
                p = p->next;
        } while ( p != root );

        q->next = p->next;
        root = p->next;
        delete(p);
}

int main()
{
        node *root = NULL;

        addElementLast(root, 100);
        addElementLast(root, 20);
        addElementLast(root, 300);
        addElementLast(root, 40);
        addElementLast(root, 50);
        cout << "Circular linked list : ";
        display(root);

        // Removing first element
        removeFirstElement(root);
        cout << "After removing first element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;

        addElementLast(root1, 1);
        cout << "Circular linked list : ";
        display(root1);

        removeFirstElement(root1);
        display(root1);

        return 0;
}
