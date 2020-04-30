#include <bits/stdc++.h>
using namespace std;

class TriDiagonalMatrix {
private:
        int *A;
        int n;
public:
        TriDiagonalMatrix(int n) {
                this->n = n;
                A = new int[3*n-2];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~TriDiagonalMatrix() {
                delete []A;
        }
};

void TriDiagonalMatrix :: setMatrix(int i, int j, int x) {
        if ( (i - j) == 0 )
                A[n+i-2] = x;
        else if ( (i - j) == 1 )
                A[i-2] = x;
        else if ( (i - j) == -1 )
                A[2*n+i-2] = x;
}

int TriDiagonalMatrix :: getMatrix(int i, int j) {
        if ( (i - j) == 0 )
                return A[n+i-2];
        else if ( (i - j) == 1 )
                return A[i-1];
        else if ( (i - j) == -1 )
                return A[2*n+i-2];
        else
                return 0;
}

int TriDiagonalMatrix :: getDimension() {
        return n;
}

void TriDiagonalMatrix :: displayMatrix() {
        for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ ) {
                        if ( (i - j) == 0 )
                                cout << A[n+i-2] << " ";
                        else if ( (i - j) == 1 )
                                cout << A[i-2] << " ";
                        else if ( (i - j) == -1 )
                                cout << A[2*n+i-2] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        TriDiagonalMatrix tdm(4);
        tdm.setMatrix(1, 1, 1);
        tdm.setMatrix(2, 2, 1);
        tdm.setMatrix(3, 3, 1);
        tdm.setMatrix(4, 4, 1);

        tdm.setMatrix(2, 1, 2);
        tdm.setMatrix(3, 2, 2);
        tdm.setMatrix(4, 3, 2);

        tdm.setMatrix(1, 2, 3);
        tdm.setMatrix(2, 3, 3);
        tdm.setMatrix(3, 4, 3);

        cout << "Tridiagonal matrix : " << endl;
        tdm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << tdm.getMatrix(2, 2) << endl;
        cout << "Index(2, 3) is : " << tdm.getMatrix(2, 3) << endl;

        return 0;
}
