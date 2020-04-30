#include <bits/stdc++.h>
using namespace std;

void validation(char ch[]) {
        for ( int i = 0; ch[i] != '\0'; i++ ) {
                if ( ch[i] >= 'a' && ch[i] <= 'z' || ch[i] >= 'A' && ch[i] <= 'Z' || ch[i] >= '0' && ch[i] <= '9' )
                        continue;
                else {
                        cout << "Not a valid string" << endl;
                        return;
                }
        }
        cout << "Valid string" << endl;
}

int main()
{
        char ch[] = "anil321";
        validation(ch);

        char ch1[] = "ani?321";
        validation(ch1);

        return 0;
}
