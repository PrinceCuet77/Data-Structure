#include <bits/stdc++.h>
using namespace std;

void permutation(char s[], int k) {
        static int A[10] = {0};
        static char res[10];
        if ( s[k] == '\0' ) {
                res[k] = '\0';
                cout << res << endl;
                return;
        } else {
                for ( int i = 0; s[i] != '\0'; i++ ) {
                        if ( A[i] == 0 ) {
                                A[i] = 1;
                                res[k] = s[i];
                                permutation(s, k+1);
                                A[i] = 0;
                        }
                }
        }
}

int main()
{
        char s[] = "ABC";
        permutation(s, 0);

        return 0;
}
