#include <bits/stdc++.h>
using namespace std;

void findingMissedElements(int ar[], int n) {
        int diff = ar[0];
        cout << "Missed values are : ";
        for ( int i = 0; i < n; i++ ) {
                if ( (ar[i] - i) != diff ) {
                        while ( (ar[i] - i) != diff ) {
                                cout << diff + i << ", ";
                                diff++;
                        }
                }
        }
        cout << endl;
}

int main()
{
        int ar[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
        int n = sizeof(ar) / sizeof(ar[0]);
        findingMissedElements(ar, n);

        return 0;
}
