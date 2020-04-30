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

void findingMin(node *current) {
        int minNode = current->data, position = 1, cnt = 0;
        while ( current != NULL ) {
                cnt++;
                if ( minNode > current->data ) {
                        minNode = current->data;
                        position = cnt;
                }
                current = current->next;
        }
        cout << "Minimum value : " << minNode << endl;
        cout << "Position : " << position << endl;
}

int main()
{
        node *root = NULL;
        addNodeLast(root, 100);
        addNodeLast(root, 20);
        addNodeLast(root, 3);
        addNodeLast(root, 40);

        cout << "Linked list : ";
        display(root);
        findingMin(root);

        return 0;
}

