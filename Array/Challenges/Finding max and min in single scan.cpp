#include <bits/stdc++.h>
using namespace std;

void findingMaxAndMin(int ar[], int n) {
        int maxValue = ar[0], minValue = ar[0];
        for ( int i = 0; i < n; i++ ) {
                maxValue = max(maxValue, ar[i]);
                minValue = min(minValue, ar[i]);
        }
        cout << "Maximum is : " << maxValue << endl;
        cout << "Minimum is : " << minValue << endl;
}

int main()
{
        int ar[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingMaxAndMin(ar, n);

        return 0;
}
