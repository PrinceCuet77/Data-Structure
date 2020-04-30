#include <bits/stdc++.h>
using namespace std;

class DiagonalMatrix {
private:
        int *A;
        int n;
public:
        DiagonalMatrix(int n) {
                this->n = n;
                A = new int[n];
        }

        void setMatrix(int i, int j, int x);
        int getMatrix(int i, int j);
        int getDimension();
        void displayMatrix();

        ~DiagonalMatrix() {
                delete []A;
        }
};

void DiagonalMatrix :: setMatrix(int i, int j, int x) {
        if ( i == j )
                A[i-1] = x;
}

int DiagonalMatrix :: getMatrix(int i, int j) {
        if ( i == j )
                return A[i-1];
        else
                return 0;
}

int DiagonalMatrix :: getDimension() {
        return n;
}

void DiagonalMatrix :: displayMatrix() {
        for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                        if ( i == j )
                                cout << A[i] << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
}

int main()
{
        DiagonalMatrix dm(4);
        dm.setMatrix(1, 1, 1);
        dm.setMatrix(2, 2, 2);
        dm.setMatrix(3, 3, 3);
        dm.setMatrix(4, 4, 4);

        cout << "Diagonal matrix : " << endl;
        dm.displayMatrix();
        cout << endl;

        cout << "Index(2, 2) is : " << dm.getMatrix(2, 2) << endl;
        cout << "Index(2, 3) is : " << dm.getMatrix(2, 3) << endl;

        return 0;
}
