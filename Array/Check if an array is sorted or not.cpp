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

bool checkingSort(Array ar) {
        int value = ar.A[0];
        for ( int i = 1; i < ar.length; i++ ) {
                if ( ar.A[i] < value )
                        return false;
                value = ar.A[i];
        }
        return true;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        bool check = checkingSort(ar);
        if ( check )
                cout << "Array is sorted" << endl;
        else
                cout << "Array is not sorted" << endl;
        Array ar1 = {{10, 40, 20, 55, 22}, 10, 5};
        cout << "Array is : ";
        Display(ar1);

        check = checkingSort(ar1);
        if ( check )
                cout << "Array is sorted" << endl;
        else
                cout << "Array is not sorted" << endl;

        return 0;
}
