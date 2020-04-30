#include <bits/stdc++.h>
using namespace std;

void findingDuplicates(int ar[], int n) {
        int lastDuplicate = ar[0] - 1;
        cout << "Duplicate elements are : ";
        for ( int i = 0; i < n-1; i++ ) {
                if ( ar[i] == ar[i+1] && ar[i] != lastDuplicate ) {
                        cout << ar[i] << ", ";
                        lastDuplicate = ar[i];
                }
        }
        cout << endl;
}

int main()
{
        int ar[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingDuplicates(ar, n);

        return 0;
}
