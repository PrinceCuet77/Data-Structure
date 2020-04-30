#include <bits/stdc++.h>
using namespace std;

class UpperTriangularMatrixUsingRowMajor {
private:
        int *A;
        int n;
public:
        UpperTriangularMatrixUsingRowMajor(int n) {
                this->n = n;
                A = new int[n*(n+1)/2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~UpperTriangularMatrixUsingRowMajor() {
                delete []A;
        }
};

void UpperTriangularMatrixUsingRowMajor :: setMatrix(int i, int j, int x) {
        if ( i <= j )
                A[(n*(i-1)-((i-2)*(i-1))/2)-(j-i)] = x;
}

int UpperTriangularMatrixUsingRowMajor :: getMatrix(int i, int j) {
        if ( i <= j )
                return A[(n*(i-1)-((i-2)*(i-1))/2)-(j-i)];
        else
                return 0;
}

int UpperTriangularMatrixUsingRowMajor :: getDimension() {
        return n;
}

void UpperTriangularMatrixUsingRowMajor :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i <= j )
                                cout << A[(n*(i-1)-((i-2)*(i-1))/2)-(j-i)] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        UpperTriangularMatrixUsingRowMajor rm(4);
        rm.setMatrix(1, 1, 1);
        rm.setMatrix(2, 2, 1);
        rm.setMatrix(3, 3, 1);
        rm.setMatrix(4, 4, 1);

        rm.setMatrix(3, 4, 2);

        rm.setMatrix(2, 3, 2);
        rm.setMatrix(2, 4, 3);

        rm.setMatrix(1, 2, 2);
        rm.setMatrix(1, 3, 3);
        rm.setMatrix(1, 4, 4);

        cout << "Upper triangular matrix(Row major method) : " << endl;
        rm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << rm.getMatrix(3, 3) << endl;
        cout << "Index(2, 1) is : " << rm.getMatrix(3, 2) << endl;
        cout << "Index(2, 3) is : " << rm.getMatrix(3, 4) << endl;

        return 0;
}
