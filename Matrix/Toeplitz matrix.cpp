#include <bits/stdc++.h>
using namespace std;

class ToeplitzMatrix {
private:
        int *A;
        int n;
public:
        ToeplitzMatrix(int n) {
                this->n = n;
                A = new int[2*n-1];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~ToeplitzMatrix() {
                delete []A;
        }
};

void ToeplitzMatrix :: setMatrix(int i, int j, int x) {
        if ( i <= j )
                A[j-i] = x;
        else if ( i > j )
                A[n+i-j-1] = x;
}

int ToeplitzMatrix :: getMatrix(int i, int j) {
        if ( i <= j )
                return A[j-i];
        else if ( i > j )
                return A[n+i-j-1];
}

int ToeplitzMatrix :: getDimension() {
        return n;
}

void ToeplitzMatrix :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i <= j )
                                cout << A[j-i] << " ";
                        else if ( i > j )
                                cout << A[n+i-j-1] << " ";
                }
                cout << endl;
        }
}

int main()
{
        ToeplitzMatrix tm(4);
        tm.setMatrix(1, 1, 1);
        tm.setMatrix(1, 2, 2);
        tm.setMatrix(1, 3, 3);
        tm.setMatrix(1, 4, 4);

        tm.setMatrix(2, 1, 8);
        tm.setMatrix(3, 1, 7);
        tm.setMatrix(4, 1, 6);

        cout << "Toeplitz matrix : " << endl;
        tm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << tm.getMatrix(2, 2) << endl;
        cout << "Index(2, 3) is : " << tm.getMatrix(2, 3) << endl;

        return 0;
}
