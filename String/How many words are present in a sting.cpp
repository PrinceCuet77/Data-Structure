#include <bits/stdc++.h>
using namespace std;

void findingWords(char s[]) {
        int word = 1;
        for ( int i = 0; s[i] != '\0'; i++ ) {
                if ( s[i] == ' ' && s[i-1] != ' ' )
                        word++;
        }
        cout << "Total words : " << word << endl;
}

int main()
{
        char ch[] = "How are you?";
        findingWords(ch);

        char ch1[] = "How are   you?";
        findingWords(ch1);

        return 0;
}
