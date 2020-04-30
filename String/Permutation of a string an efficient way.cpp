#include <bits/stdc++.h>
using namespace std;

void permutation(char s[], int l, int h) {
        if ( l == h ) {
                cout << s << endl;
                return;
        } else {
                for ( int i = l; i < h; i++ ) {
                        swap(s[i], s[l]);
                        permutation(s, l+1, h);
                        swap(s[i], s[l]);
                }
        }
}

int main()
{
        char s[] = "ABC";
        permutation(s, 0, 3);

        return 0;
}
