#include <bits/stdc++.h>
using namespace std;

class CQueue {
private:
        int fnt;
        int rear;
        int sz;
        int *q;
public:
        CQueue(int n);
        ~CQueue();

        void Display();
        void Enqueue(int x);
        int Dequeue();
        int Size();
};

CQueue :: CQueue(int n) {
        fnt = rear = -1;
        sz = n;
        q = new int[n];
}

CQueue :: ~CQueue() {
        delete []q;
}

void CQueue :: Enqueue(int x) {
        if ( (rear+1) % sz == fnt ) {
                cout << "Queue is full" << endl;
                return;
        }
        rear = (rear+1) % sz;
        q[rear] = x;
}

int CQueue :: Dequeue() {
        int x = -1;
        if ( fnt == rear ) {
                cout << "Queue is empty" << endl;
                return x;
        }
        fnt = (fnt+1) % sz;
        x = q[fnt];
        return x;
}

void CQueue :: Display() {
        int i = fnt+1;
        do {
                cout << q[i] << " ";
                i = (i+1) % sz;
        } while ( i != (rear+1) % sz );
        cout << endl;
}

int CQueue :: Size() {
        if ( rear >= fnt )
                return rear - fnt;
        else
                return sz - fnt + rear + 1;
}

int main()
{
        CQueue qu(5);
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
