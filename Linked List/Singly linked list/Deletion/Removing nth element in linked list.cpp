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

void deleteNodeNthPosition( node *&root, int position ) {
        node *current = root;
        if ( position == 1 ) {
                root = current->next;
                delete(current);
                return;
        }
        node *prev = NULL;
        for ( int i = 1; i <= position-1; i++ ) {
                prev = current;
                current = current->next;
        }

        prev->next = current->next;
        delete(current);
}

int main()
{
        node *root = NULL;

        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);

        cout << "Linked list : ";
        display(root);

        deleteNodeNthPosition(root, 1);
        cout << "After removing 1st(root) node : ";
        display(root);

        deleteNodeNthPosition(root, 4);
        cout << "After removing 4th node : ";
        display(root);

        deleteNodeNthPosition(root, 5);
        cout << "After removing 5th(last) node : ";
        display(root);

        return 0;
}

