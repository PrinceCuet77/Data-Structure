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

void concatenatingTwoDoublyLinkedList(node *root1, node *&root2) {
        node *p = root1;
        while ( p->next != NULL )
                p = p->next;
        p->next = root2;
        root2->prev = p;
        root2 = NULL;
}

int main()
{
        node *root1 = NULL;
        addElementLast(root1, 10);
        addElementLast(root1, 20);
        addElementLast(root1, 30);
        addElementLast(root1, 40);

        cout << "Doubly linked list(root1) : ";
        display(root1);

        node *root2 = NULL;
        addElementLast(root2, 1);
        addElementLast(root2, 2);
        addElementLast(root2, 3);
        addElementLast(root2, 4);

        cout << "Doubly linked list(root2) : ";
        display(root2);

        // Concatenating two doubly linked list
        concatenatingTwoDoublyLinkedList(root1, root2);
        display(root1);
        display(root2);

        return 0;
}
