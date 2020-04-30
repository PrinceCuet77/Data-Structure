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

void addNode( node *&root, int data ) {
        node *current = root;

        node *temp = new node(); // Taking place for new element
        temp->data = data;

        if ( root->data > data ) {
                temp->next = root;
                root = temp;
                return;
        }
        node *prev = NULL;
        while ( current != NULL ) {
                if ( data < current->data )
                        break;
                prev = current;
                current = current->next;
        }
        temp->next = current;
        prev->next = temp;
}

int main()
{
        node *root = NULL;

        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);

        cout << "Sorted linked list : ";
        display(root);

        addNode(root, 33);
        cout << "After adding 33 : ";
        display(root);

        addNode(root, 100);
        cout << "After adding 100 : ";
        display(root);

        addNode(root, 3);
        cout << "After adding 3 : ";
        display(root);

        return 0;
}

