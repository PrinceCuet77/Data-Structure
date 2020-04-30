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

void findingMax(node *current) {
        int maxNode = current->data, position = -1, cnt = 0;
        while ( current != NULL ) {
                cnt++;
                if ( maxNode < current->data ) {
                        maxNode = current->data;
                        position = cnt;
                }
                current = current->next;
        }
        cout << "Maximum value : " << maxNode << endl;
        cout << "Position : " << position << endl;
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
        findingMax(root);

        return 0;
}
