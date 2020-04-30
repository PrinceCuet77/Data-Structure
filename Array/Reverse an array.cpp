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

void reverseArray(Array &ar) {
        for ( int i = 0, j = ar.length-1; i < j; i++, j-- )
                swap(ar.A[i], ar.A[j]);
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        reverseArray(ar);
        cout << "Reverse the array : ";
        Display(ar);

        return 0;
}
