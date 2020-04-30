#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void insertIntoHash(node *&root, int value) {
        node *temp = new node();
        temp->data = value;
        temp->next = NULL;

        if ( root == NULL ) // For inserting first element or root
                root = temp;
        else {
                if ( root->data > value ) { // For inserting before root
                        temp->next = root;
                        root = temp;
                        return;
                }

                node *current = root, *prev = NULL;
                while ( current != NULL ) {
                        if ( current->data > value )
                                break;
                        prev = current;
                        current = current->next;
                }

                prev->next = temp;
                temp->next = current;
        }
}

bool searchToHash(node *temp, int key) {
        while ( temp != NULL ) {
                if ( temp->data == key )
                        return true;
                temp = temp->next;
        }

        return false;
}

void deleteElementFromHash(node *&root, int key) {
        if ( root->data == key ) { // If I have to delete first element or root
                node *temp = root;
                root = NULL;
                delete(temp);
        }
        else {
                node *current = root, *prev = root;
                while ( current != NULL ) {
                        if ( current->data == key )
                                break;
                        prev = current;
                        current = current->next;
                }

                prev->next = current->next;
                delete(current);
        }
}

void display(node *temp) {
        if ( temp == NULL ) {
                printf("None\n");
                return;
        }

        while ( temp != NULL ) {
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("\n");
}

int hashKey(int n) { // Finding which index to store 'n'
        return (n % 10);
}

int main()
{
        node *h[10];

        for ( int i = 0; i < 10; i++ )
                h[i] = NULL;

        int a[] = {3, 6, 12, 24, 88, 55, 39, 26, 15, 38, 9, 65, 35};
        int n = sizeof(a) / sizeof(a[0]);

        // Insertion
        for ( int i = 0; i < n; i++ )
                insertIntoHash(h[hashKey(a[i])], a[i]);

        // Display
        for ( int i = 0; i < 10; i++ ) {
                printf("Index %d is : ", i);
                display(h[i]);
        }
        printf("\n");

        // Searching
        if ( searchToHash(h[hashKey(38)], 38) == true )
                printf("38 is found\n");

        if ( searchToHash(h[hashKey(11)], 11) == false )
                printf("11 is not found\n");
        printf("\n");

        // Deletion
        deleteElementFromHash(h[hashKey(12)], 12);

        for ( int i = 0; i < 10; i++ ) {
                printf("Index %d is : ", i);
                display(h[i]);
        }
        printf("\n");

        deleteElementFromHash(h[hashKey(55)], 55);

        for ( int i = 0; i < 10; i++ ) {
                printf("Index %d is : ", i);
                display(h[i]);
        }
        printf("\n");

        return 0;
}
