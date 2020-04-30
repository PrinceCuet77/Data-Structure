#include <bits/stdc++.h>
using namespace std;

int main()
{
        char a[] = "finding friends";
        long int H = 0, x = 0;
        set < char > st;

        for ( int i = 0; a[i] != '\0'; i++ ) {
                x = 1;
                if ( a[i] >= 'a' && a[i] <= 'z' )
                        x = x << (a[i] - 97);
                else if ( a[i] >= 'A' && a[i] <= 'Z' )
                        x = x << (a[i] - 65);
                if ( (H & x) > 0 ) // Bit masking
                        st.insert(a[i]);
                else
                        H = x | H; // Bit merging
        }

        cout << "Duplicate characters are : ";
        for ( char ch : st )
                cout << ch << ", ";
        cout << endl;

        return 0;
}
