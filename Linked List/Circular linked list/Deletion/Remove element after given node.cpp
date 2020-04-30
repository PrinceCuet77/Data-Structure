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

void removeElementAfterGivenNode(node *&root, int data) {
        node *p = root;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p->data != data );

        q = p;
        p = p->next;
        q->next = p->next;
        if ( p == root ) { // If I want to delete root node then change the root
                root = p->next;
        }
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
        cout << endl;

        // Removing element after given node
        removeElementAfterGivenNode(root, 100);
        cout << "After removing node 20 : ";
        display(root);

        removeElementAfterGivenNode(root, 300);
        cout << "After removing node 40 : ";
        display(root);

        removeElementAfterGivenNode(root, 50);
        cout << "After removing node 100(root) : ";
        display(root);

        return 0;
}
