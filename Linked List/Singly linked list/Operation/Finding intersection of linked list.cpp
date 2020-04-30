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

void findingIntersection(node *first, node *second) {
        stack < node* > fi, se;
        while ( first != NULL ) {
                fi.push(first);
                first = first->next;
        }

        while ( second != NULL ) {
                se.push(second);
                second = second->next;
        }

        node *intersectionNode = NULL;
        while ( fi.top() == se.top() ) {
                intersectionNode = fi.top();
                fi.pop();
                se.pop();
        }

        if ( intersectionNode == NULL )
                cout << "No intersection is found" << endl;
        else
                cout << "Intersection is found at " << intersectionNode->data << endl;
}

int main()
{
        node *first = NULL;
        addNodeLast(first, 8);
        addNodeLast(first, 6);
        addNodeLast(first, 3);
        addNodeLast(first, 9);
        addNodeLast(first, 10);
        addNodeLast(first, 4);
        addNodeLast(first, 2);
        addNodeLast(first, 12);

        cout << "First linked list : ";
        display(first);

        node *second = NULL;
        addNodeLast(second, 20);
        addNodeLast(second, 30);
        addNodeLast(second, 40);

        node *temp = first->next->next->next->next;
        node *temp2 = second->next->next;
        temp2->next = temp;

        cout << "Second linked list : ";
        display(second);

        findingIntersection(first, second);

        return 0;
}

