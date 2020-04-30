#include <bits/stdc++.h>
using namespace std;

void countingDuplicates(int ar[], int n) {
        int lastDuplicate = ar[0] - 1;
        for ( int i = 0; i < n-1; i++ ) {
                if ( ar[i] == ar[i+1] && ar[i] != lastDuplicate ) {
                        int j = i+1;
                        while ( ar[i] == ar[j] )
                                j++;
                        cout << ar[i] << " occurs in " << j-i << " time(s)" << endl;
                        lastDuplicate = ar[i];
                        i = j-1;
                }
        }
        cout << endl;
}

int main()
{
        int ar[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
        int n = sizeof(ar) / sizeof(ar[0]);

        countingDuplicates(ar, n);

        return 0;
}
