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

void SetMembership(Array ar, int key) {
        int low = 0, high = ar.length - 1;
        while ( low <= high ) {
                int mid = (low + high) / 2;
                if ( ar.A[mid] == key ) {
                        cout << key << " is a member of set" << endl;
                        return;
                } else if ( ar.A[mid] < key )
                        low = mid + 1;
                else if ( ar.A[mid] > key )
                        high = mid - 1;
        }
        cout << key << " is not a member of set" << endl;
}

int main()
{
        Array ar1 = {{21, 29, 45, 68, 92}, 10, 5};
        cout << "Array1 is : ";
        Display(ar1);

        SetMembership(ar1, 45);
        SetMembership(ar1, 22);

        return 0;
}
