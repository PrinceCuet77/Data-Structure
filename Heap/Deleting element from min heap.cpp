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

void deleteFromHeap(int a[], int &n) {
        a[1] = a[n-1]; // Copy last element
        n--; // Size reduced by 1
        int i = 1, j = 2 * i; // j is left child of i

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

void display(int a[], int n) {
        for ( int i = 1; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int main()
{
        int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        display(a, n);

        // Calling function
        for ( int i = 1; i < n; i++ )
                insertIntoHeap(a, i);

        // Inserting given array into min heap in place or in same array
        printf("Min heap : ");
        display(a, n);

        // Deletion from min heap
        deleteFromHeap(a, n);

        printf("Min heap after deletion : ");
        display(a, n);

        deleteFromHeap(a, n);

        printf("Min heap after deletion : ");
        display(a, n);

        return 0;
}
