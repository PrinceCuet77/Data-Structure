#include <bits/stdc++.h>
using namespace std;

void findingMissedElement(int ar[], int n) {
        int diff = ar[0];
        for ( int i = 0; i < n; i++ ) {
                if ( (ar[i] - i) != diff ) {
                        cout << "Missed element is : " << diff + i << endl;
                        return;
                }
        }
}

int main()
{
        int ar[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
        int n = sizeof(ar) / sizeof(ar[0]);
        findingMissedElement(ar, n);

        return 0;
}
