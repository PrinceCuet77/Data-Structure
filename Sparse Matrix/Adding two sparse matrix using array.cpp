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
        int nonZeroElement; // Number of non zero element
        Element *element; // Calling dynamic array
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

        Sparse operator + (Sparse &s);

        friend istream & operator >> (istream &is, Sparse &s);
        friend ostream & operator << (ostream &os, Sparse &s);
};

istream & operator >> (istream &is, Sparse &s) { // Taking non zero elements as input
        cout << "Enter number of non zero elements : " << endl;
        for ( int i = 0; i < s.nonZeroElement; i++ )
                cin >> s.element[i].i >> s.element[i].j >> s.element[i].value;

        return is;
}

ostream & operator << (ostream &os, Sparse &s) { // Display sparse matrix
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

Sparse Sparse :: operator + (Sparse &s) { // Adding two sparse matrix
        int i = 0, j = 0, k = 0;
        if ( row != s.row || column != s.column )
                return Sparse(0, 0, 0);

        Sparse *sum = new Sparse(row, column, nonZeroElement + s.nonZeroElement);
        while ( i < nonZeroElement && j < s.nonZeroElement ) {
                if ( element[i].i < s.element[j].i ) // Cells who will come first will copy first
                        sum->element[k++] = element[i++];
                else if ( element[i].i > s.element[j].i )
                        sum->element[k++] = s.element[j++];
                else {
                        if ( element[i].j < s.element[j].j )
                                sum->element[k++] = element[i++];
                        else if ( element[i].j > s.element[j].j )
                                sum->element[k++] = s.element[j++];
                        else { // Adding because two cells are in same position
                                sum->element[k] = element[i++];
                                sum->element[k++].value += s.element[j++].value;
                        }
                }
        }
        while ( i < nonZeroElement )
                sum->element[k++] = element[i++];
        while ( j < s.nonZeroElement )
                sum->element[k++] = s.element[j++];

        sum->nonZeroElement = k;
        return *sum;
}

int main()
{
        Sparse mat1(4, 5, 5);
        cin >> mat1;
        cout << mat1;

        Sparse mat2(4, 5, 5);
        cin >> mat2;
        cout << mat2;

        Sparse sum = mat1 + mat2;
        cout << sum;

        return 0;
}
