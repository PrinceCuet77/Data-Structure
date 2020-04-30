#include <bits/stdc++.h>
using namespace std;

struct Array {
        int A[10];
        int size;
        int length;
};

void Display(Array ar) {
        for ( int i = 0; i < ar.length; i++ )
                cout << ar.A[i] << " ";
        cout << endl;
}

int BinarySearch(Array ar, int key) {
        int low = 0;
        int high = ar.length-1;
        while ( low <= high ) {
                int mid = (low + high) / 2;
                if ( ar.A[mid] == key )
                        return mid;
                else if ( ar.A[mid] > key )
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        return -1;
}

int reverseBinarySearch(Array ar, int low, int high, int key) {
        if ( low > high )
                return -1;
        int mid = (low + high) / 2;
        if ( ar.A[mid] == key )
                return mid;
        else if ( ar.A[mid] > key )
                return reverseBinarySearch(ar, low, mid-1, key);
        return reverseBinarySearch(ar, mid+1, high, key);
}

int main()
{
        Array ar = {{5, 8, 9, 11, 15, 20, 23}, 10, 7};
        cout << "Array is : ";
        Display(ar);

        // For iterative binary search
        int key = 15;
        int index = BinarySearch(ar, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        key = 25;
        index = BinarySearch(ar, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        // For reverse binary search
        key = 15;
        index = reverseBinarySearch(ar, 0, ar.length-1, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        key = 25;
        index = reverseBinarySearch(ar, 0, ar.length-1, key);
        if ( index == -1 )
                cout << key << " is not found" << endl << endl;
        else
                cout << key << " is found at " << index << endl << endl;

        return 0;
}
