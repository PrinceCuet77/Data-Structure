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

                node *temp = new node();
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

void removingBeforeGivenNode(node *&root, int givenNode) {
        node *p = root;
        if ( root->next->data == givenNode ) {
                root = root->next;
                root->prev = NULL;
                delete(p);
                return;
        }
        node *q = NULL;
        while ( p->next != NULL ) {
                if ( p->next->data == givenNode )
                        break;
                q = p;
                p = p->next;
        }
        q->next = p->next;
        if ( p->next )
                p->next->prev = q;
        delete(p);
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

        // Removing element before given node
        removingBeforeGivenNode(root, 40);
        cout << "Removing the node before 40 : ";
        display(root);

        removingBeforeGivenNode(root, 20);
        cout << "Removing the node before 20 : ";
        display(root);

        return 0;
}
