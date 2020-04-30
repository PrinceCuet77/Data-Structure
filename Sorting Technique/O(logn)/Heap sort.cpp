#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

void HeapSort(int a[], int &n) {
        int x = a[1];
        a[1] = a[n-1]; // Copy last element
        n--; // Size reduced by 1
        int i = 1, j = 2 * i; // j is left child of i

        while ( j < n - 1 ) {
                if ( a[j+1] > a[j] ) // Compare between left child and right child
                        j++;
                if ( a[i] < a[j] ) { // store which one is large to its parent
                        swap(a[i], a[j]);
                        i = j;
                        j = 2 * i;
                }
                else
                        break;
        }
        a[n] = x; // Store it to last for sorting
}

int main()
{
        int a[] = {0, 40, 35, 30, 15, 10, 25, 5};
        int n = sizeof(a) / sizeof(a[0]);
        int sz = n;

        printf("Given array : ");
        printArray(a, n);

        for ( int i = 1; i < sz; i++ )
                HeapSort(a, n);
        n = sz;

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
