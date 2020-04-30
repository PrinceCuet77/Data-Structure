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

void arrangingArray(Array &ar) {
        int i = 0, j = ar.length-1;
        while ( i < j ) {
                while ( ar.A[i] < 0 ) i++;
                while ( ar.A[j] >= 0 ) j--;
                if ( i < j )
                        swap(ar.A[i], ar.A[j]);
        }
}

int main()
{
        Array ar = {{2, -3, 25, 10, -15, -7}, 10, 6};
        cout << "Array is : ";
        Display(ar);

        arrangingArray(ar);
        cout << "After re-arranging : ";
        Display(ar);

        return 0;
}
