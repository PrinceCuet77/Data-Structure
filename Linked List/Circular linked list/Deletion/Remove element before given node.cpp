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

void removeElementBeforeGivenNode(node *&root, int data) {
        node *p = root;
        node *q = NULL;
        if ( p->next->data == data ) { // If I want to delete root
                do {
                        q = p;
                        p = p->next;
                } while ( p != root );
                root = p->next;
        } else {
                do {
                        if ( p->next->data == data )
                                break;
                        q = p;
                        p = p->next;
                } while ( p != root );
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
        cout << endl;

        // Removing element before given node
        removeElementBeforeGivenNode(root, 40);
        cout << "After removing 300 : ";
        display(root);

        removeElementBeforeGivenNode(root, 100);
        cout << "After removing 50 : ";
        display(root);

        removeElementBeforeGivenNode(root, 20);
        cout << "After removing 100(root) : ";
        display(root);

        return 0;
}
