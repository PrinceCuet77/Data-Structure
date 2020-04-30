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

void Difference(Array ar1, Array ar2, Array &ar3) {
        int i = 0, j = 0, k = 0;
        while ( i < ar1.length && j < ar2.length ) {
                if ( ar1.A[i] == ar2.A[j] ) {
                        i++;
                        j++;
                } else if ( ar1.A[i] < ar2.A[j] )
                        ar3.A[k++] = ar1.A[i++];
                else if ( ar1.A[i] > ar2.A[j] )
                        j++;
        }
        while ( i < ar1.length )
                ar3.A[k++] = ar1.A[i++];
        while ( j < ar2.length )
                ar3.A[k++] = ar2.A[j++];
        ar3.length = k;
}

int main()
{
        Array ar1 = {{2, 9, 21, 28, 35}, 10, 5};
        cout << "Array1 is : ";
        Display(ar1);

        Array ar2 = {{2, 3, 9, 18, 28}, 10, 5};
        cout << "Array2 is : ";
        Display(ar2);

        Array ar3 = {{}, 20, 0};

        Difference(ar1, ar2, ar3);
        cout << "Array3 is : ";
        Display(ar3);

        return 0;
}
