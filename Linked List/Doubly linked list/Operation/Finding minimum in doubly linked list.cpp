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

int findingMinimumElement(node *root) {
        int minValue = 1e3;
        node *p = root;
        while ( p != NULL ) {
                minValue = min(minValue, p->data);
                p = p->next;
        }
        return minValue; // Returning minimum value
}

int main()
{
        node *root = NULL;
        addElementLast(root, 50);
        addElementLast(root, 200);
        addElementLast(root, 30);
        addElementLast(root, 40);

        cout << "Doubly linked list : ";
        display(root);

        // Finding minimum in doubly linked list
        cout << "The minimum is : " << findingMinimumElement(root) << endl;

        return 0;
}
