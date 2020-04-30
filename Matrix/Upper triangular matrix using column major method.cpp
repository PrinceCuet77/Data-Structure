#include <bits/stdc++.h>
using namespace std;

class UpperTriangularMatrixUsingColumnMajor {
private:
        int *A;
        int n;
public:
        UpperTriangularMatrixUsingColumnMajor(int n) {
                this->n = n;
                A = new int[n*(n+1)/2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~UpperTriangularMatrixUsingColumnMajor() {
                delete []A;
        }
};

void UpperTriangularMatrixUsingColumnMajor :: setMatrix(int i, int j, int x) {
        if ( i <= j )
                A[(j*(j-1))/2+(i-1)] = x;
}

int UpperTriangularMatrixUsingColumnMajor :: getMatrix(int i, int j) {
        if ( i <= j )
                return A[(j*(j-1))/2+(i-1)];
        else
                return 0;
}

int UpperTriangularMatrixUsingColumnMajor :: getDimension() {
        return n;
}

void UpperTriangularMatrixUsingColumnMajor :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i <= j )
                                cout << A[(j*(j-1))/2+(i-1)] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        UpperTriangularMatrixUsingColumnMajor cm(4);
        cm.setMatrix(1, 1, 1);
        cm.setMatrix(2, 2, 1);
        cm.setMatrix(3, 3, 1);
        cm.setMatrix(4, 4, 1);

        cm.setMatrix(3, 4, 2);

        cm.setMatrix(2, 3, 2);
        cm.setMatrix(2, 4, 3);

        cm.setMatrix(1, 2, 2);
        cm.setMatrix(1, 3, 3);
        cm.setMatrix(1, 4, 4);

        cout << "Upper triangular matrix(Column major method) : " << endl;
        cm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << cm.getMatrix(3, 3) << endl;
        cout << "Index(2, 1) is : " << cm.getMatrix(3, 2) << endl;
        cout << "Index(2, 3) is : " << cm.getMatrix(3, 4) << endl;

        return 0;
}
