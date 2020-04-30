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

void BucketSort(int a[], int n) {
        int maxValue = findMax(a, n); // Finding max element in given array
        vector < int > cnt[maxValue+1]; // Taking max sized vector(linked list)

        for ( int i = 0; i < n; i++ )
                cnt[a[i]].push_back(a[i]); // Stored element where it should be

        for ( int i = 0, k = 0; i <= maxValue; i++ ) {
                if ( cnt[i].size() != 0 ) {
                        for ( int j = 0; j < cnt[i].size(); j++ )
                                a[k++] = cnt[i][j];
                        cnt[i].clear();
                }
        }
}

int main()
{
        int a[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        BucketSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
