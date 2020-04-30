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

int LinearSearch(Array ar, int key) {
        for ( int i = 0; i < ar.length-1; i++ ) {
                if ( ar.A[i] == key )
                        return i;
        }
        return -1;
}

int ImprovingLinearSearch(Array &ar, int key) {
        for ( int i = 0; i < ar.length-1; i++ ) {
                if ( ar.A[i] == key ) {
                        swap(ar.A[i], ar.A[0]); // Cause next time same key searching time will reduce
                        return i;
                }
        }
        return -1;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        int key = 3;
        int index = LinearSearch(ar, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        key = 10;
        index = LinearSearch(ar, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        key = 4;
        index = ImprovingLinearSearch(ar, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        cout << "Array is : ";
        Display(ar);

        return 0;
}
