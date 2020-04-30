#include <bits/stdc++.h>
using namespace std;

class LowerTriangularMatrixUsingColumnMajor {
private:
        int *A;
        int n;
public:
        LowerTriangularMatrixUsingColumnMajor(int n) {
                this->n = n;
                A = new int[n*(n+1)/2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~LowerTriangularMatrixUsingColumnMajor() {
                delete []A;
        }
};

void LowerTriangularMatrixUsingColumnMajor :: setMatrix(int i, int j, int x) {
        if ( i >= j )
                A[(n*(j-1)-((j-2)*(j-1))/2)-(i-j)] = x;
}

int LowerTriangularMatrixUsingColumnMajor :: getMatrix(int i, int j) {
        if ( i >= j )
                return A[(n*(j-1)-((j-2)*(j-1))/2)-(i-j)];
        else
                return 0;
}

int LowerTriangularMatrixUsingColumnMajor :: getDimension() {
        return n;
}

void LowerTriangularMatrixUsingColumnMajor :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i >= j )
                                cout << A[(n*(j-1)-((j-2)*(j-1))/2)-(i-j)] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        LowerTriangularMatrixUsingColumnMajor cm(4);
        cm.setMatrix(1, 1, 1);
        cm.setMatrix(2, 2, 2);
        cm.setMatrix(3, 3, 3);
        cm.setMatrix(4, 4, 4);

        cm.setMatrix(2, 1, 1);

        cm.setMatrix(3, 1, 1);
        cm.setMatrix(3, 2, 2);

        cm.setMatrix(4, 1, 1);
        cm.setMatrix(4, 2, 2);
        cm.setMatrix(4, 3, 3);

        cout << "Lower triangular matrix(Column major method) : " << endl;
        cm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << cm.getMatrix(3, 3) << endl;
        cout << "Index(2, 1) is : " << cm.getMatrix(3, 2) << endl;
        cout << "Index(2, 3) is : " << cm.getMatrix(3, 4) << endl;

        return 0;
}
