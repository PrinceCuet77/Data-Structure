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

void linearSearch( node *current, int data ) {
        int cnt = 0;
        while ( current != NULL ) {
                cnt++;
                if ( data == current->data ) {
                        cout << data << " is found at " << cnt << endl;
                        return;
                }
                current = current->next;
        }
        cout << data << " is not found" << endl;
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

        linearSearch(root, 30);
        linearSearch(root, 33);

        return 0;
}
