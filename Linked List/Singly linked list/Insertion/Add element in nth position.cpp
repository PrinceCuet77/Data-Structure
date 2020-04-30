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
        while ( current != NULL ) {
                cout << current->data << " "; // Just printing all the elements
                current = current->next;
        }
        cout << endl;
}

void addNodeInNthPosition( node *&root, int data, int position ) {
        node *current = root;

        node *temp = new node();
        temp->data = data;

        if ( position == 1 ) {
                temp->next = root;
                root = temp;
                return;
        }
        for ( int i = 1; i < position-1; i++ ) {
                current = current->next;
        }

        temp->next = current->next;

        current->next = temp;
}

int main()
{
        node *root = NULL;

        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);

        cout << "Linked list : ";
        display(root);

        addNodeInNthPosition(root, 3, 3);
        cout << "After adding 3 in 3rd position : ";
        display(root);

        addNodeInNthPosition(root, 100, 6);
        cout << "After adding 100 in 6th position : ";
        display(root);

        addNodeInNthPosition(root, 1, 1);
        cout << "After adding 1 in 3st position : ";
        display(root);

        return 0;
}

