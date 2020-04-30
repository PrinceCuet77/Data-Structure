#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

void Merge(int ar[], int L[], int R[], int nl, int rl) {
        int i = 0, j = 0, k = 0;
        while ( i < nl && j < rl ) {            // Sorting L and R array and store to a array
                if ( L[i] <= R[j] )
                        ar[k++] = L[i++];
                else
                        ar[k++] = R[j++];
        }

        while ( i < nl )                        // Adding remaining L array element
                ar[k++] = L[i++];

        while ( j < rl )                        // Adding remaining R array element
                ar[k++] = R[j++];
}

void MergeSort(int ar[], int n) {
        if ( n < 2 )                            // Base case
                return;

        int mid = n / 2;                        // Dividing two array

        int L[mid], R[n-mid];
        for ( int i = 0; i < mid; i++ )         // Copy first mid-1 element to L array
                L[i] = ar[i];

        for ( int i = mid; i < n; i++ )         // Copy mid to n-mid element to R array
                R[i-mid] = ar[i];

        MergeSort(L, mid);                      // Recursive calling for L array
        MergeSort(R, n-mid);                    // Recursive calling for R array
        Merge(ar, L, R, mid, n-mid);            // Sorting L and R array
}

int main()
{
        int a[] = {8, 3, 7, 4, 9, 2, 6, 5};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        MergeSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
