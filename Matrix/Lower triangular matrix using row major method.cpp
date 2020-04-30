#include <bits/stdc++.h>
using namespace std;

class LowerTriangularMatrixUsingRowMajor {
private:
        int *A;
        int n;
public:
        LowerTriangularMatrixUsingRowMajor(int n) {
                this->n = n;
                A = new int[n*(n+1)/2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~LowerTriangularMatrixUsingRowMajor() {
                delete []A;
        }
};

void LowerTriangularMatrixUsingRowMajor :: setMatrix(int i, int j, int x) {
        if ( i >= j )
                A[(i*(i-1))/2+(j-1)] = x;
}

int LowerTriangularMatrixUsingRowMajor :: getMatrix(int i, int j) {
        if ( i >= j )
                return A[(i*(i-1))/2+(j-1)];
        else
                return 0;
}

int LowerTriangularMatrixUsingRowMajor :: getDimension() {
        return n;
}

void LowerTriangularMatrixUsingRowMajor :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i >= j )
                                cout << A[(i*(i-1))/2+(j-1)] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        LowerTriangularMatrixUsingRowMajor rm(4);
        rm.setMatrix(1, 1, 1);
        rm.setMatrix(2, 2, 2);
        rm.setMatrix(3, 3, 3);
        rm.setMatrix(4, 4, 4);

        rm.setMatrix(2, 1, 1);

        rm.setMatrix(3, 1, 1);
        rm.setMatrix(3, 2, 2);

        rm.setMatrix(4, 1, 1);
        rm.setMatrix(4, 2, 2);
        rm.setMatrix(4, 3, 3);

        cout << "Lower triangular matrix(row major method) : " << endl;
        rm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << rm.getMatrix(3, 3) << endl;
        cout << "Index(2, 1) is : " << rm.getMatrix(3, 2) << endl;
        cout << "Index(2, 3) is : " << rm.getMatrix(3, 4) << endl;

        return 0;
}
