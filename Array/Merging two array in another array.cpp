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

void MergingTwoArray(Array ar1, Array ar2, Array &ar3) {
        int i = 0, j = 0, k = 0;
        while ( i < ar1.length && j < ar2.length ) {
                if ( ar1.A[i] < ar2.A[j] )
                        ar3.A[k++] = ar1.A[i++];
                else
                        ar3.A[k++] = ar2.A[j++];
        }
        while ( i < ar1.length )
                ar3.A[k++] = ar1.A[i++];
        while ( j < ar2.length )
                ar3.A[k++] = ar2.A[j++];
        ar3.length = k;
}

int main()
{
        Array ar1 = {{2, 6, 10, 15, 25, 44, 55}, 10, 7};
        cout << "Array1 is : ";
        Display(ar1);

        Array ar2 = {{3, 7, 8, 18}, 10, 4};
        cout << "Array2 is : ";
        Display(ar2);

        Array ar3 = {{0}, 20, 0};
        cout << "Array3 is : ";
        Display(ar3);

        MergingTwoArray(ar1, ar2, ar3);
        cout << "Array3 is now : ";
        Display(ar3);

        return 0;
}
