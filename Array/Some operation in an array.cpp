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

bool validation(int index, int length) {
        if ( index < 0 ) {
                cout << "Index must be zero or positive value" << endl;
                return false;
        }
        if ( index > length ) {
                cout << "Index must be less than array length" << endl;
                return false;
        }
        return true;
}

int getValue(Array ar, int index) {
        if ( validation(index, ar.length) == false )
                return -1;
        return ar.A[index];
}

void setValue(Array &ar, int index, int value) {
        if ( validation(index, ar.length) == false )
                return;
        ar.A[index] = value;
}

int maxValue(Array ar) {
        int findingMaxValue = ar.A[0];
        for ( int i = 1; i < ar.length; i++ )
                findingMaxValue = max(findingMaxValue, ar.A[i]);
        return findingMaxValue;
}

int minValue(Array ar) {
        int findingMinValue = ar.A[0];
        for ( int i = 1; i < ar.length; i++ )
                findingMinValue = min(findingMinValue, ar.A[i]);
        return findingMinValue;
}

int sumValue(Array ar) {
        int findingSumValue = 0;
        for ( int i = 0; i < ar.length; i++ )
                findingSumValue += ar.A[i];
        return findingSumValue;
}

double avgValue(Array ar) {
        return sumValue(ar) / ar.length;
}

int main()
{
        Array ar = {{110, 29, 13, 54, 75}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        cout << "Value at index 2 is : " << getValue(ar, 2) << endl;

        setValue(ar, 2, 100);
        cout << "Now array is : ";
        Display(ar);

        cout << "Maximum value is : " << maxValue(ar) << endl;
        cout << "Minimum value is : " << minValue(ar) << endl;
        cout << "Summation is : " << sumValue(ar) << endl;
        cout << "Avg. value is : " << avgValue(ar) << endl;

        return 0;
}
