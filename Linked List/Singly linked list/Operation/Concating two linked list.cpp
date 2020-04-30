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

void concateTwoLinkedList(node *current, node *&second) {
        while ( current->next != NULL )
                current = current->next;
        current->next = second;
        second = NULL;
}

int main()
{
        node *first = NULL, *second = NULL;

        addNodeLast(first, 10);
        addNodeLast(first, 20);
        addNodeLast(first, 30);
        addNodeLast(first, 40);

        cout << "First linked list : ";
        display(first);

        addNodeLast(second, 1);
        addNodeLast(second, 2);
        addNodeLast(second, 3);
        addNodeLast(second, 4);

        cout << "Second linked list : ";
        display(second);

        concateTwoLinkedList(first, second);

        cout << "After concatenating two linked list : ";
        display(first);
        display(second);

        return 0;
}
