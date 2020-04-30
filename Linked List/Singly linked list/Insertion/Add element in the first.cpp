#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void addNodeFirst( node *&root, int data ) {
        if ( root == NULL ) {
                root = new node(); // Adding first node
                root->data = data;
                root->next = NULL;
        } else {
                node *current = new node();
                current->data = data;
                current->next = root;

                root = current;
        }
}

void display(node *current) {
        while ( current != NULL ) {
                cout << current->data << " "; // Just printing all the elements
                current = current->next;
        }
        cout << endl;
}

int main()
{
        node *root = NULL;

        addNodeFirst(root, 10);
        addNodeFirst(root, 20);
        addNodeFirst(root, 30);

        cout << "Linked list : ";
        display(root);

        return 0;
}

