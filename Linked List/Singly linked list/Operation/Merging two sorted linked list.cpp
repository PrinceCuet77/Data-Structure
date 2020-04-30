#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void addNodeLast( node *&root, int data ) {
        if ( root == NULL ) { // Inserting first element
                root = new node();
                root->data = data;
                root->next = NULL;
        } else {
                node *current = root;
                while ( current->next != NULL ) // Traversing before last element
                        current = current->next;

                node *temp = new node(); // Taking place for new element
                temp->data = data;
                temp->next = NULL; // It will be last element so taking null

                current->next = temp;
        }
}

void display(node *current) {
        if ( current == NULL ) {
                cout << "Root node is null" << endl;
                return;
        }
        while ( current != NULL ) {
                cout << current->data << " "; // Just printing all the elements
                current = current->next;
        }
        cout << endl;
}

void mergingSortedLinkedList(node *first, node *&second) {
        node *third = NULL, *last = NULL;
        if ( first->data < second->data ) {
                third = first;
                last = first;
                first = first->next;
                last->next = NULL;
        } else {
                third = second;
                last = second;
                second = second->next;
                last->next = NULL;
        }
        while ( first != NULL && second != NULL ) {
                if ( first->data < second->data ) {
                        last->next = first;
                        last = first;
                        first = first->next;
                        last->next = NULL;
                } else {
                        last->next = second;
                        last = second;
                        second = second->next;
                        last->next = NULL;
                }
        }
        if ( first != NULL )
                last->next = first;
        else
                last->next = second;
        first = third;
        second = NULL;
}

int main()
{
        node *first = NULL;
        addNodeLast(first, 10);
        addNodeLast(first, 20);
        addNodeLast(first, 30);
        addNodeLast(first, 40);

        cout << "First sorted linked list : ";
        display(first);

        node *second = NULL;
        addNodeLast(second, 15);
        addNodeLast(second, 19);
        addNodeLast(second, 35);
        addNodeLast(second, 44);
        addNodeLast(second, 42);
        addNodeLast(second, 46);
        addNodeLast(second, 47);
        addNodeLast(second, 49);

        cout << "Second sorted linked list : ";
        display(second);

        mergingSortedLinkedList(first, second);

        cout << "After merging : ";
        display(first);
        display(second);

        return 0;
}

