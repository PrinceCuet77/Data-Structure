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

void addNodeAfterGivenNode( node *root, int data, int givenData ) {
        node *current = root;
        while ( current != NULL ) {
                if ( current->data == givenData )
                        break;
                current = current->next;
        }

        node *temp = new node(); // Taking place for new element
        temp->data = data;
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

        addNodeAfterGivenNode(root, 3, 20);

        cout << "After adding 3 after the node 20 : ";
        display(root);

        addNodeAfterGivenNode(root, 5, 40);

        cout << "After adding 5 after the node 40 : ";
        display(root);

        return 0;
}
