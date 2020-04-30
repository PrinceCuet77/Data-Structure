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

void addElementAtFirst(node *&root, int data) {
        node *p = root;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root );

        node *temp = new node();
        temp->data = data;
        temp->next = p;

        q->next = temp;
        root = temp; // Changing the root
}

int main()
{
        node *root = NULL;

        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 30);

        cout << "Circular linked list : ";
        display(root);

        // Adding element at first(root)
        addElementAtFirst(root, 5);
        addElementAtFirst(root, 3);

        cout << "After adding 5 and 3 : ";
        display(root);

        return 0;
}
