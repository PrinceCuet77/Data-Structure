#include <bits/stdc++.h>
using namespace std;

class SymmetricMatrixUsingRowMajor {
private:
        int *A;
        int n;
public:
        SymmetricMatrixUsingRowMajor(int n) {
                this->n = n;
                A = new int[n*(n+1)/2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~SymmetricMatrixUsingRowMajor() {
                delete []A;
        }
};

void SymmetricMatrixUsingRowMajor :: setMatrix(int i, int j, int x) {
        A[(i*(i-1))/2+(j-1)] = x;
}

int SymmetricMatrixUsingRowMajor :: getMatrix(int i, int j) {
        if ( i < j )
                swap(i, j);
        return A[(i*(i-1))/2+(j-1)];
}

int SymmetricMatrixUsingRowMajor :: getDimension() {
        return n;
}

void SymmetricMatrixUsingRowMajor :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( i < j ) {
                                swap(i, j);
                                cout << A[(i*(i-1))/2+(j-1)] << " ";
                                swap(i, j);
                        } else
                                cout << A[(i*(i-1))/2+(j-1)] << " ";
                }
                cout << endl;
        }
}

int main()
{
        SymmetricMatrixUsingRowMajor rm(4);
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

        cout << "Symmetric matrix(row major method) : " << endl;
        rm.displayMatrix();
        cout << endl;

        cout << "Index(1, 0) is : " << rm.getMatrix(2, 1) << endl;
        cout << "Index(0, 1) is : " << rm.getMatrix(1, 2) << endl;

        return 0;
}
