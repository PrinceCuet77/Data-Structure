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

void InsertValue(Array &ar, int value) {
        int index = ar.length;
        for ( int i = ar.length-1; i >= 0; i-- ) {
                if ( ar.A[i] < value )
                        break;
                ar.A[i+1] = ar.A[i];
                index--;
        }
        ar.A[index] = value;
        ar.length++;
}

int main()
{
        Array ar = {{10, 20, 30, 40, 50}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        InsertValue(ar, 65);
        InsertValue(ar, 5);
        InsertValue(ar, 25);
        cout << "After inserting in sorted array : ";
        Display(ar);

        return 0;
}
