#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};
node *Front = NULL, *Rear = NULL;

void enqueue(int data) {
        node *temp = new node();
        if ( temp == NULL ) { // If heap is full
                cout << "Queue is full" << endl;
                return;
        }
        temp->data = data;
        temp->next = NULL;

        if ( Front == NULL ) // No one is in queue
                Front = Rear = temp;
        else {
                Rear->next = temp;
                Rear = temp;
        }
}

void display() {
        node *current = Front;
        while ( current != NULL ) {
                cout << current->data << " "; // Displaying nodes
                current = current->next;
        }
        cout << endl;
}

int dequeue() {
        if ( Front == NULL ) {
                cout << "Queue is empty" << endl;
                return -1;
        }
        node *temp = Front;
        int poppedValue = temp->data;
        Front = Front->next;
        delete(temp);
        return poppedValue;
}

int sizeOfQueue() {
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
        enqueue(6);
        enqueue(3);

        cout << "Queue is : ";
        display();

        cout << "Size of Queue is : " << sizeOfQueue() << endl;

        int value = dequeue();
        if ( value != -1 )
                cout << value << " is popped" << endl;

        cout << "After popping element from queue : ";
        display();

        enqueue(1);

        value = dequeue();
        if ( value != -1 )
                cout << value << " is popped" << endl;

        value = dequeue();
        if ( value != -1 )
                cout << value << " is popped" << endl;

        value = dequeue();
        if ( value != -1 )
                cout << value << " is popped" << endl;

        cout << "Size of Queue is : " << sizeOfQueue() << endl;

        return 0;
}
