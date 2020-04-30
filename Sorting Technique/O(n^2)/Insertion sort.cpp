#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n) {
        for ( int i = 1; i < n; i++ ) {
                int value = a[i]; // Which element I want to place it's right place
                int index = i;

                while ( index > 0 && a[index-1] > value ) { // index > 0 because index-1 >= 0
                        a[index] = a[index-1];
                        index--;
                }

                a[index] = value;
        }
}

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int main()
{
        int a[] = {8, 5, 7, 3, 2};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        InsertionSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
