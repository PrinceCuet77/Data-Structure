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

        friend istream & operator >> (istream &is, Polynomial &p);
        friend ostream & operator << (ostream &os, Polynomial &p);

        int evaluationOfEquation(int x);
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

int Polynomial :: evaluationOfEquation(int x) {
        int result = 0;
        for ( int i = 0; i < n; i++ )
                result += tm[i].coff * pow(x, tm[i].exp);

        return result;
}

int main()
{
        Polynomial pn(5);
        cin >> pn;
        cout << endl;

        cout << pn;
        cout << endl;

        cout << "Value is : " << pn.evaluationOfEquation(2) << endl;

        return 0;
}
