#include <bits/stdc++.h>
using namespace std;

void comparingTwoString(char ch1[], char ch2[]) {
        int len1 = strlen(ch1), len2 = strlen(ch2);
        if ( len1 < len2 )
                cout << "First string is small" << endl;
        else if ( len1 > len2 )
                cout << "Second string is small" << endl;
        else {
                for ( int i = 0; i < len1; i++ ) {
                        if ( ch1[i] < ch2[i] ) {
                                cout << "First string is small" << endl;
                                return;
                        } else if ( ch1[i] > ch2[i] ) {
                                cout << "Second string is small" << endl;
                                return;
                        }
                }
                cout << "Two strings are same" << endl;
        }
}

int main()
{
        char ch1[] = "friends", ch2[] = "friends";
        comparingTwoString(ch1, ch2);

        return 0;
}
