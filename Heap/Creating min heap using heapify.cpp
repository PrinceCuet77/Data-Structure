#include <bits/stdc++.h>
using namespace std;

void heapifyForMaxHeap(int a[], int i, int n) {
        int j = 2 * i; // j is left child of i

        while ( j < n - 1 ) {
                if ( a[j+1] < a[j] ) // Compare between left child and right child
                        j++;
                if ( a[i] > a[j] ) { // store which one is large to its parent
                        swap(a[i], a[j]);
                        i = j;
                        j = 2 * i;
                }
                else
                        break;
        }
}

int main()
{
        int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");

        for ( int i = n-1; i >= 1; i-- )
                heapifyForMaxHeap(a, i, n);

        printf("Min heap using heapify : ");
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");

        return 0;
}
