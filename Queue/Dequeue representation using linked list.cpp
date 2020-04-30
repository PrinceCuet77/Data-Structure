#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};
node *Front = NULL, *Rear = NULL;

bool isEmpty() {
        if ( Front == NULL && Rear == NULL )
                return true;
        return false;
}

void enqueueFromFront(int data) {
        node *temp = new node();
        if ( temp == NULL ) {
                printf("Dequeue is full\n");
                return;
        }
        temp->data = data;
        temp->next = NULL;

        if ( isEmpty() )
                Front = Rear = temp;
        else {
                temp->next = Front;
                Front = temp;
        }
}

void enqueueFromRear(int data) {
        node *temp = new node();
        if ( temp == NULL ) { // If heap is full
                printf("Dequeue is full\n");
                return;
        }
        temp->data = data;
        temp->next = NULL;

        if ( isEmpty() ) // No one is in queue
                Front = Rear = temp;
        else {
                Rear->next = temp;
                Rear = temp;
        }
}

int dequeueFromFront() {
        if ( isEmpty() ) {
                printf("Dequeue is empty\n");
                return -1;
        }

        node *temp = Front;
        Front = Front->next;

        int poppedValue = temp->data;
        delete(temp);

        return poppedValue;
}

int dequeueFromRear() {
        if ( isEmpty() ) {
                printf("Dequeue is empty\n");
                return -1;
        }

        node *current = Front;
        node *prev = NULL;

        while ( current->next != NULL ) {
                prev = current;
                current = current->next;
        }

        Rear = prev;
        prev->next = NULL;

        int poppedValue = current->data;
        delete(current);

        return poppedValue;
}

void display() {
        node *current = Front;

        while ( current != NULL ) {
                printf("%d ", current->data); // Displaying nodes
                current = current->next;
        }
        printf("\n");
}

int sizeOfDeque() {
        node *current = Front;
        int cnt = 0;

        while ( current != NULL ) {
                cnt++;
                current = current->next;
        }

        return cnt;
}

int main()
{
        enqueueFromFront(6);
        enqueueFromFront(8);
        enqueueFromRear(3);
        enqueueFromRear(1);

        printf("Dequeue is : ");
        display();

        printf("Size of dequeue : %d\n", sizeOfDeque());

        dequeueFromFront();
        dequeueFromRear();

        printf("Dequeue is : ");
        display();

        printf("Size of dequeue : %d\n", sizeOfDeque());

        return 0;
}
