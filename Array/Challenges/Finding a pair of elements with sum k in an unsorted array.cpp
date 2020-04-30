#include <bits/stdc++.h>
using namespace std;

void findingPairOfElement(int ar[], int n, int k) {
        for ( int i = 0; i < n-1; i++ ) {
                for ( int j = n-1; i < j; j-- ) {
                        if ( ar[i] + ar[j] == k )
                                cout << "( " << ar[i] << ", " << ar[j] << " )" << endl;
                }
        }
}

int main()
{
        int ar[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingPairOfElement(ar, n, 10);

        return 0;
}
