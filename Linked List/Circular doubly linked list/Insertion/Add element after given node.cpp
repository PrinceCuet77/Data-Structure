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

void addElementAfterGivenNode(node *root, int data, int givenNode) {
        node *p = root;
        node *q = NULL;
        do {
                if ( p->data == givenNode ) {
                        q = p;
                        p = p->next;
                        break;
                }
                q = p;
                p = p->next;
        } while ( p != root );

        node *temp = new node();
        temp->data = data;

        temp->next = p;
        temp->prev = q;

        q->next = p->prev = temp;

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

        // Adding element after given node
        addElementAfterGivenNode(root, 5, 30);
        cout << "Adding 5 after 30 : ";
        display(root);

        addElementAfterGivenNode(root, 10, 50);
        cout << "Adding 10 after 50 : ";
        display(root);

        return 0;
}
