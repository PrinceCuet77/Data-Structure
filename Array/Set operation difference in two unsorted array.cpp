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
        int k = 0;
        for ( int i = 0; i < ar1.length; i++ ) {
                bool flag = false;
                for ( int j = 0 ; j < ar2.length; j++ ) {
                        if ( ar1.A[i] == ar2.A[j] ) {
                                flag = true;
                                break;
                        }
                }
                if ( flag == false )
                        ar3.A[k++] = ar1.A[i];
        }
        ar3.length = k;
}

int main()
{
        Array ar1 = {{3, 5, 10, 4, 6}, 10, 5};
        cout << "Array1 is : ";
        Display(ar1);

        Array ar2 = {{12, 4, 7, 2, 5}, 10, 5};
        cout << "Array2 is : ";
        Display(ar2);

        Array ar3 = {{}, 20, 0};

        Difference(ar1, ar2, ar3);
        cout << "Array3 is : ";
        Display(ar3);

        return 0;
}
