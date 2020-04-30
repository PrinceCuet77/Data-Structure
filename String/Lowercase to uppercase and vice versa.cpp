#include <bits/stdc++.h>
using namespace std;

int main()
{
        char a[] = "welcome", A[] = "WELCOME";
        for ( int i = 0; a[i] != '\0'; i++ )
                a[i] = a[i] - 32;
        cout << "Converted uppercase : " << a << endl;

        for ( int i = 0; A[i] != '\0'; i++ )
                A[i] = A[i] + 32;
        cout << "converted lowercase : " << A << endl;

        return 0;
}
