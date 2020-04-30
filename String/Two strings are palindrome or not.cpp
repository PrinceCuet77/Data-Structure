#include <bits/stdc++.h>
using namespace std;

void palindrome(char ch[]) {
        int len = strlen(ch);
        for ( int i = 0; i < len/2; i++ ) {
                if ( ch[i] != ch[len-i-1] ) {
                        cout << "Two strings are not palindrome" << endl;
                        return;
                }
        }
        cout << "Two strings are palindrome" << endl;
}

int main()
{
        char ch[] = "madam";
        palindrome(ch);

        char ch1[] = "prince";
        palindrome(ch1);

        return 0;
}
