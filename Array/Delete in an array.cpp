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

int Delete(Array &ar, int index) {
        if ( validation(index, ar.length) == false )
                return -1;
        int deletedValue = ar.A[index];
        for ( int i = index; i < ar.length-1; i++ )
                ar.A[i] = ar.A[i+1];
        ar.length--;
        return deletedValue;
}

int main()
{
        Array ar = {{1, 2, 3, 4, 5}, 10, 5};
        cout << "Array is : ";
        Display(ar);

        int deletedValue = Delete(ar, 2);
        if ( deletedValue == -1 )
                cout << "Nothing is deleted" << endl;
        else
                cout << "Deleted value is : " << deletedValue << endl;
        cout << "Array is : ";
        Display(ar);
        cout << endl;

        deletedValue = Delete(ar, -2);
        cout << "Array is : ";
        Display(ar);

        return 0;
}
