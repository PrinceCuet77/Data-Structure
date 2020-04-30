#include <bits/stdc++.h>
using namespace std;

void reverseAString(char ch[]) {
        int len = strlen(ch);
        for ( int i = 0; i < len/2; i++ )
                swap(ch[i], ch[len-i-1]);
        cout << "Reverse a string is : " << ch << endl;
}

int main()
{
        char ch[] = "Prince";
        reverseAString(ch);

        return 0;
}
