#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

void ShellSort(int a[], int n) {
        for ( int gap = n / 2; gap >= 1; gap /= 2) {
                for ( int i = gap; i < n; i++ ) {
                        int temp = a[i];
                        int j = i - gap;

                        while ( j >= 0 && a[j] > temp ) {
                                a[j+gap] = a[j];
                                j = j - gap;
                        }

                        a[j+gap] = temp;
                }
        }
}

int main()
{
        int a[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
        int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
        printArray(a, n);

        ShellSort(a, n);

        printf("Sorted array : ");
        printArray(a, n);

        return 0;
}
