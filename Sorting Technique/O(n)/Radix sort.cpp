#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int findMax(int a[], int n) {
        int maxValue = a[0];

        for ( int i = 1; i < n; i++ )
                maxValue = max(maxValue, a[i]);

        return maxValue;
}

void BucketSort(int a[], int n, int index) {
        vector < int > cnt[10];

        for ( int i = 0; i < n; i++ )
                cnt[ (a[i]/index) % 10 ].push_back(a[i]);

        for ( int i = 0, k = 0; i < 10; i++ ) {
                if ( cnt[i].size() != 0 ) {
                        for ( int j = 0; j < cnt[i].size(); j++ )
                                a[k++] = cnt[i][j];
                        cnt[i].clear();
                }
        }
}

void RadixSort(int a[], int n) {
        int maxValue = findMax(a, n);

        for ( int index = 1; maxValue / index > 0; index *= 10 )
                BucketSort(a, n, index);
}

int main()
{
        int a[] = {237, 146, 254, 348, 152, 163, 235, 48, 36, 62};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        RadixSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
