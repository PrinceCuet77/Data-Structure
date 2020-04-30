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

void removeDuplicateElement(node *&root) {
        node *p = root->next;
        node *q = root;
        do {
                if ( p->data == q->data ) { // If duplicate element is found then one of them is deleted
                        q->next = p->next;
                        delete(p);
                        p = q->next;
                } else { // If duplicate element is not found then move forward
                        q = p;
                        p = p->next;
                }
        } while ( p != root );
}

int main()
{
        node *root = NULL;
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 20);
        addElementLast(root, 20);
        addElementLast(root, 30);
        addElementLast(root, 30);
        addElementLast(root, 40);
        addElementLast(root, 50);
        addElementLast(root, 50);
        cout << "Sorted circular linked list : ";
        display(root);

        // Removing duplicate elements in sorted circular linked list
        removeDuplicateElement(root);
        cout << "After removing duplicate elements : ";
        display(root);

        return 0;
}
