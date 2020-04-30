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

bool sortedOrNot(node *current) {
        int x = current->data;
        while ( current != NULL ) {
                if ( current->data < x )
                        return false;
                x = current->data;
                current = current->next;
        }
        return true;
}

int main()
{
        node *root = NULL;

        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);
        addNodeLast(root, 100);

        cout << "Linked list : ";
        display(root);

        bool flag = sortedOrNot(root);
        if ( flag )
                cout << "Linked list is sorted" << endl;
        else
                cout << "Linked list is not sorted" << endl;
        cout << endl;

        addNodeLast(root, 15);
        addNodeLast(root, 25);

        display(root);

        flag = sortedOrNot(root);
        if ( flag )
                cout << "Linked list is sorted" << endl;
        else
                cout << "Linked list is not sorted" << endl;

        return 0;
}
