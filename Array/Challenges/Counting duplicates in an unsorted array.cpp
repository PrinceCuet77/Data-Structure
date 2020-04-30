#include <bits/stdc++.h>
using namespace std;

void countingDuplicates(int ar[], int n) {
        for ( int i = 0; i < n-1; i++ ) {
                int cnt = 1;
                for ( int j = i+1; j < n; j++ ) {
                        if ( ar[i] == ar[j] && ar[i] != -1 ) {
                                cnt++;
                                ar[j] = -1;
                        }
                }
                if ( cnt > 1 )
                        cout << ar[i] << " occurs in " << cnt << " time(s)" << endl;
        }
        cout << endl;
}

int main()
{
        int ar[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
        int n = sizeof(ar) / sizeof(ar[0]);

        countingDuplicates(ar, n);

        return 0;
}
