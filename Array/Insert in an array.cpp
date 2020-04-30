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

bool validation(int index, int length) {
        if ( index < 0 ) {
                cout << "Index must be zero or positive value" << endl;
                return false;
        }
        if ( index > length ) {
                cout << "Index must be less than array length" << endl;
                return false;
        }
        return true;
}

void Insert(Array &ar, int index, int value) {
        if ( validation(index, ar.length) == false )
                return;
        for ( int i = ar.length; i > index; i-- )
                ar.A[i] = ar.A[i-1];
        ar.A[index] = value;
        ar.length++;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        Insert(ar, 2, 10);
        cout << "After inserting 10 at 2nd position : ";
        Display(ar);

        Insert(ar, -2, 20);
        cout << "Array is : ";
        Display(ar);

        Insert(ar, 10, 100);
        cout << "Array is : ";
        Display(ar);

        return 0;
}
