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

void leftShift(Array &ar) {
        for ( int i = 1; i < ar.length; i++ )
                swap(ar.A[i], ar.A[i-1]);
        ar.A[ar.length-1] = 0;
}

void rightShift(Array &ar) {
        for ( int i = ar.length-1; i > 0; i-- )
                swap(ar.A[i], ar.A[i-1]);
        ar.A[0] = 0;
}

void leftRotate(Array &ar) {
        int value = ar.A[0];
        for ( int i = 1; i < ar.length; i++ )
                swap(ar.A[i], ar.A[i-1]);
        ar.A[ar.length-1] = value;
}

void rightRotate(Array &ar) {
        int value = ar.A[ar.length-1];
        for ( int i = ar.length-1; i > 0; i-- )
                swap(ar.A[i], ar.A[i-1]);
        ar.A[0] = value;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        cout << "After left shift, array is : ";
        leftShift(ar);
        Display(ar);

        cout << "After left rotate, array is : ";
        leftRotate(ar);
        Display(ar);

        cout << "After right shift, array is : ";
        rightShift(ar);
        Display(ar);

        cout << "After right rotate, array is : ";
        rightRotate(ar);
        Display(ar);



        return 0;
}
