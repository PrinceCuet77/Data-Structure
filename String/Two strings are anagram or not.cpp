#include <bits/stdc++.h>
using namespace std;

int main()
{
        char a[] = "medical", b[] = "decimal";
        int H[30] = {0}; // Using hashing

        for ( int i = 0; a[i] != '\0'; i++ )
                H[a[i]-97]++;

        bool flag = false;
        for ( int i = 0; b[i] != '\0'; i++ ) {
                H[b[i]-97]--;
                if ( H[b[i]-97] < 0 ) {
                        cout << "Two strings are not anagram" << endl;
                        flag = true;
                }
        }
        if ( flag == false )
                cout << "Two strings are anagram" << endl;

        return 0;
}
