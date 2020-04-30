#include <bits/stdc++.h>
using namespace std;

class Term {
public:
        int coff;
        int exp;
};

class Polynomial {
private:
        int n;
        Term *tm;
public:
        Polynomial(int n) {
                this->n = n;
                tm = new Term[this->n];
        }

        ~Polynomial() {
                delete []tm;
        }

        Polynomial operator + (Polynomial &p);

        friend istream & operator >> (istream &is, Polynomial &p);
        friend ostream & operator << (ostream &os, Polynomial &p);
};

istream & operator >> (istream &is, Polynomial &p) {
        cout << "Enter all co-efficients of polynomial" << endl;
        for ( int i = 0; i < p.n; i++ )
                cin >> p.tm[i].coff;

        cout << "Enter all exponents of polynomial" << endl;
        for ( int i = 0; i < p.n; i++ )
                cin >> p.tm[i].exp;
        return is;
}

ostream & operator << (ostream &os, Polynomial &p) {
        cout << "Polynomial is : ";
        for ( int i = 0; i < p.n; i++ ) {
                if ( i == p.n-1 )
                        cout << p.tm[i].coff << "*X^" << p.tm[i].exp << endl;
                else
                        cout << p.tm[i].coff << "*X^" << p.tm[i].exp << " + ";
        }
        return os;
}

Polynomial Polynomial :: operator + (Polynomial &p) {
        int i = 0, j = 0, k = 0;
        Polynomial *sum = new Polynomial(n+p.n);
        while ( i < n && j < p.n ) {
                if ( tm[i].exp > p.tm[j].exp )
                        sum->tm[k++] = tm[i++];
                else if ( tm[i].exp < p.tm[j].exp )
                        sum->tm[k++] = p.tm[j++];
                else {
                        sum->tm[k] = tm[i++];
                        sum->tm[k++].coff += p.tm[j++].coff;
                }
        }
        while ( i < n )
                sum->tm[k++] = tm[i++];
        while ( j < p.n )
                sum->tm[k++] = p.tm[j++];
        sum->n = k;
        return *sum;
}

int main()
{
        Polynomial pn1(5);
        cin >> pn1;
        cout << pn1;
        cout << endl;

        Polynomial pn2(4);
        cin >> pn2;
        cout << pn2;
        cout << endl;

        Polynomial pn = pn1 + pn2;
        cout << pn;

        return 0;
}
