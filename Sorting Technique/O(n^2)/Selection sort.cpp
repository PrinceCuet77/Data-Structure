#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n) {
	for ( int i = 0; i < n-1; i++ ) {
		int minIndex = i;                           // Storing the min index
		for ( int j = i+1; j < n; j++ ) {       // Finding the smallest number's index in the array
			if ( a[j] < a[minIndex] )
				minIndex = j;
		}
		swap(a[i], a[minIndex]);
	}
}

void printArray(int a[], int n) {
        for ( int i = 0; i < n; i++ )
                printf("%d ", a[i]);
        printf("\n");
}

int main()
{
	int a[] = {8, 6, 3, 2, 5, 4};
	int n = sizeof(a) / sizeof(a[0]);

        printf("Given array : ");
	printArray(a, n);

	SelectionSort(a, n);

	printf("Sorted array : ");
	printArray(a, n);

	return 0;
}
