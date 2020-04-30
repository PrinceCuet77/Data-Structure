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

void concatenatingTwoCircularLinkedList(node *&root1, node *&root2) {
        node *p = root1;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root1 );

        q->next = root2; // Adding two circular linked list

        p = root2;
        q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root2 );

        q->next = root1;
        root2 = NULL;
}

int main()
{
        node *root = NULL;
        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 30);
        cout << "Circular linked list(root) : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementLast(root1, 1);
        addElementLast(root1, 2);
        addElementLast(root1, 3);
        cout << "Circular linked list(root1) : ";
        display(root1);
        cout << endl;

        // Concatenating two circular linked list
        concatenatingTwoCircularLinkedList(root, root1);
        cout << "Adding two circular linked list : ";
        display(root);
        display(root1);

        return 0;
}
