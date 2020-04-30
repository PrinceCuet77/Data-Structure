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

void removeNthElement(node *&root, int position) {
        node *p = root;
        node *q = NULL;
        if ( position == 1 ) { // If removing first element
                if ( p->next == root ) { // If it has only one element
                        root = NULL;
                        delete(p);
                        return;
                }
                do {
                        q = p;
                        p = p->next;
                } while ( p != root );
                root = p->next;
        }
        for ( int i = 0; i < position - 1; i++ ) {
                q = p;
                p = p->next;
        }
        q->next = p->next;
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

        // Removing nth element
        removeNthElement(root, 3);
        cout << "After removing 3th element : ";
        display(root);

        removeNthElement(root, 4);
        cout << "After removing 4th element : ";
        display(root);

        removeNthElement(root, 1);
        cout << "After removing 1st element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementLast(root1, 1);
        cout << "Circular linked list : ";
        display(root1);

        // Removing nth element
        removeNthElement(root1, 1);
        display(root1);

        return 0;
}
