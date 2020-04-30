#include <bits/stdc++.h>
using namespace std;

struct Array {
        int A[10];
        int size;
        int length;
};

void Display(Array ar) {
        for ( int i = 0; i < ar.length; i++ )
                cout << ar.A[i] << " ";
        cout << endl;
}

void Append(Array &ar, int value) {
        if ( ar.length >= ar.size ) {
                cout << "Array is full" << endl;
                return;
        }
        ar.A[ar.length++] = value;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        Append(ar, 6);
        cout << "After adding 6 at last : ";
        Display(ar);

        return 0;
}
