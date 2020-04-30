#include <bits/stdc++.h>
using namespace std;

int main()
{
        char a[] = "finding friends";
        int H[30] = {0};
        set < char > st;

        for ( int i = 0; a[i] != '\0'; i++ )
                H[a[i]-97]++;

        for ( int i = 0; i < 26; i++ ) {
                if ( H[i] > 1 )
                        st.insert((char)97+i);
        }

        cout << "Duplicate characters are : ";
        for ( char ch : st )
                cout << ch << ", ";
        cout << endl;

        return 0;
}
