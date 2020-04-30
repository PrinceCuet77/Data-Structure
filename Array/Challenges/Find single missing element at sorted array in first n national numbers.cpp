#include <bits/stdc++.h>
using namespace std;

void findingMissedElement(int ar[], int n) {
        int sum = 0;
        for ( int i = 0; i < n; i++ )
                sum += ar[i];

        int missedValue = (((n+1) * (n+2)) / 2);
        missedValue -= sum;
        cout << "Missing element is : " << missedValue << endl;
}

int main()
{
        int ar[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
        int n = sizeof(ar) / sizeof(ar[0]);
        findingMissedElement(ar, n);

        return 0;
}
