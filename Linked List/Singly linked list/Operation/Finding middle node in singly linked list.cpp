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

void findingMiddleNode(node *root) {
        node *p = root;
        node *q = root;
        while ( q ) { // Tortoise and hare technique
                q = q->next;
                if ( q )
                        q = q->next;
                if ( q )
                        p = p->next;
        }
        cout << p->data << endl;
}

int main()
{
        node *root = NULL;
        addNodeLast(root, 10);
        addNodeLast(root, 20);
        addNodeLast(root, 30);
        addNodeLast(root, 40);

        cout << "Singly linked list : ";
        display(root);

        cout << "Middle node : ";
        findingMiddleNode(root);
        cout << endl;

        node *root1 = NULL;
        addNodeLast(root1, 100);
        addNodeLast(root1, 200);
        addNodeLast(root1, 300);
        addNodeLast(root1, 400);
        addNodeLast(root1, 500);
        addNodeLast(root1, 600);
        addNodeLast(root1, 700);

        cout << "Singly linked list : ";
        display(root1);

        cout << "Middle node : ";
        findingMiddleNode(root1);

        return 0;
}
