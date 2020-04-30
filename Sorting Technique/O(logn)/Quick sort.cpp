#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int Partition(int a[], int start, int finish) {
        int pivot = a[finish]; // Last element is taken as pivot
        int pIndex = start; // Checking started from 'start'

        for ( int i = start; i < finish; i++ ) {
                if ( a[i] <= pivot ) { // Finding less or equal element from pivot
                        swap(a[i], a[pIndex]);
                        pIndex++;
                }
        }

        swap(a[pIndex], a[finish]);

        return pIndex; // Returning pivot index
}

void QuickSort(int a[], int start, int finish) {
        if ( start < finish ) { // Base condition
                int pIndex = Partition(a, start, finish); // Finding pivot index
                QuickSort(a, start, pIndex-1); // Left side of pivot index will go for quick sort
                QuickSort(a, pIndex+1, finish); // Right side of pivot index will go for quick sort
        }
}

int main()
{
        int a[] = {50, 70, 60, 10, 40, 80, 20, 90, 30};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        QuickSort(a, 0, n-1);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
