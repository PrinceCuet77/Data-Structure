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
        for ( int i = 0; i < ar.length; i++ ) {
                if ( ar.A[i] == key ) {
                        cout << key << " is a member of set" << endl;
                        return;
                }
        }
        cout << key << " is not a member of set" << endl;
}

int main()
{
        Array ar1 = {{92, 59, 21, 48, 25}, 10, 5};
        cout << "Array1 is : ";
        Display(ar1);

        SetMembership(ar1, 21);
        SetMembership(ar1, 22);

        return 0;
}
