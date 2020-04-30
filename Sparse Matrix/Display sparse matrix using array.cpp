#include <bits/stdc++.h>
using namespace std;

class Element {
public:
        int i; // Row
        int j; // Column
        int value; // Value
};

class Sparse {
private:
        int row;
        int column;
        int nonZeroElement;
        Element *element;
public:
        Sparse(int row, int column, int nonZeroElement) {
                this->row = row;
                this->column = column;
                this->nonZeroElement = nonZeroElement;
                element = new Element[this->nonZeroElement];
        }
        ~Sparse() {
                delete []element;
        }

        friend istream & operator >> (istream &is, Sparse &s);
        friend ostream & operator << (ostream &os, Sparse &s);
};

istream & operator >> (istream &is, Sparse &s) {
        cout << "Enter number of non zero elements : " << endl;
        for ( int i = 0; i < s.nonZeroElement; i++ )
                cin >> s.element[i].i >> s.element[i].j >> s.element[i].value;

        return is;
}

ostream & operator << (ostream &os, Sparse &s) {
        cout << endl << "Sparse matrix is : " << endl;
        int k = 0;
        for ( int i = 1; i <= s.row; i++ ) {
                for ( int j = 1; j <= s.column; j++ ) {
                        if ( s.element[k].i == i && s.element[k].j == j )
                                cout << s.element[k++].value << " ";
                        else
                                cout << 0 << " ";
                }
                cout << endl;
        }
        return os;
}

int main()
{
        Sparse mat(5, 5, 5);
        cin >> mat;
        cout << mat;

        return 0;
}
