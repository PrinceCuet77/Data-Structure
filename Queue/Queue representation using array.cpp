#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
        int fnt;
        int rear;
        int sz;
        int *q;
public:
        Queue(int n);
        ~Queue();

        void Display();
        void Enqueue(int x);
        int Dequeue();
        int Size();
};

Queue :: Queue(int n) {
        fnt = rear = -1;
        sz = n;
        q = new int[n];
}

Queue :: ~Queue() {
        delete []q;
}

void Queue :: Enqueue(int x) {
        if ( rear == sz-1 ) {
                cout << "Queue is full" << endl;
                return;
        }
        rear++;
        q[rear] = x;
}

int Queue :: Dequeue() {
        int x = -1;
        if ( fnt == rear ) {
                cout << "Queue is empty" << endl;
                return x;
        }
        x = q[fnt+1];
        fnt++;
        return x;
}

void Queue :: Display() {
        for ( int i = fnt+1; i <= rear; i++ )
                cout << q[i] << " ";
        cout << endl;
}

int Queue :: Size() {
        return rear - fnt;
}

int main()
{
        Queue qu(5);
        qu.Enqueue(10);
        qu.Enqueue(20);
        qu.Enqueue(30);

        cout << "Queue is : ";
        qu.Display();

        cout << qu.Dequeue() << " is popped" << endl;

        cout << "Size of queue is : " << qu.Size() << endl;

        cout << "Queue is : ";
        qu.Display();

        cout << qu.Dequeue() << " is popped" << endl;
        cout << qu.Dequeue() << " is popped" << endl;
        cout << qu.Dequeue() << " is popped" << endl;

        return 0;
}
