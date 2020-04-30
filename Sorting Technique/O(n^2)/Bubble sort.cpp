#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n) {
        for ( int i = 0; i < n; i++ ) {
                bool flag = true;
                for ( int j = 0; j < n-i-1; j++ ) {
                        if ( a[j] > a[j+1] ) {
                                swap(a[j], a[j+1]);
                                flag = false;
                        }
                }
                if ( flag )
                        break;
        }
}

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int main()
{
        int a[] = {8, 3, 5, 6, 2, 1, 7};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array is : ");
        printArray(a, n);

        BubbleSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
