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

void addElementBeforeGivenNode(node *&root, int data, int givenNode) {
        node *p = root;

        node *temp = new node();
        temp->data = data;
        if ( root->data == givenNode ) {
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
        do {
                if ( p->data == givenNode )
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

        // Adding element before given node
        addElementBeforeGivenNode(root, 5, 10);
        cout << "Adding 5 before 10 : ";
        display(root);

        addElementBeforeGivenNode(root, 10, 30);
        cout << "Adding 10 before 30 : ";
        display(root);

        return 0;
}
