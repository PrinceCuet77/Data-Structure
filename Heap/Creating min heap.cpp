#include <bits/stdc++.h>
using namespace std;

void insertIntoHeap(int a[], int n) {
        int temp = a[n], i = n;

        while ( i > 1 && temp < a[i/2] ) { // If n's parent is greater than it's child (i/2)
                swap(a[i], a[i/2]);
                i /= 2; // Position must be update to it's parent
        }

        a[i] = temp; // Update element in proper position
}

int main()
{
        int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");

        // Calling function
        for ( int i = 1; i < n; i++ )
                insertIntoHeap(a, i);

        // Inserting given array into min heap in place or in same array
        printf("Min heap : ");
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");

        return 0;
}
