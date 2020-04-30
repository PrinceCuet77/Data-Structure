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

void CountSort(int a[], int n) {
        int maxValue = findMax(a, n); // Finding max element in given array
        int cnt[maxValue+1]; // Take max sized array
        memset(cnt, 0, sizeof(cnt)); // New array initialized with 0

        for ( int i = 0; i < n; i++ )
                cnt[a[i]]++; // Stored element as index and increment one

        for ( int i = 0, k = 0; i <= maxValue; i++ ) {
                if ( cnt[i] != 0 ) {
                        while ( cnt[i] != 0 ) {
                                a[k++] = i; // Restore element to given arrays
                                cnt[i]--;
                        }
                }
        }
}

int main()
{
        int a[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        CountSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
