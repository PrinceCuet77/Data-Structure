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

void removeLastElement(node *&root) {
        node *p = root;
        if ( p->next == root ) { // If it has only one element
                root = NULL;
                delete(p);
                return;
        }
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p->next != root );

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

        // Removing last element
        removeLastElement(root);
        cout << "After removing last element : ";
        display(root);
        cout << endl;

        node *root1 = NULL;
        addElementLast(root1, 50);
        addElementLast(root1, 60);
        cout << "Circular linked list : ";
        display(root1);

        removeLastElement(root1);
        cout << "After removing last element : ";
        display(root1);
        cout << endl;

        node *root2 = NULL;
        addElementLast(root2, 500);
        cout << "Circular linked list : ";
        display(root2);

        removeLastElement(root2);
        display(root2);

        return 0;
}
