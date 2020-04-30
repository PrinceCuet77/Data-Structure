#include <bits/stdc++.h>
using namespace std;

int main()
{
        char ch[] = "How are you?";

        int vowel = 0, consonant = 0;
        for ( int i = 0; ch[i] != '\0'; i++ ) {
                if ( ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' ||
                    ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U'  )
                        vowel++;
                else if ( ch[i] >= 'b' && ch[i] <= 'z' || ch[i] >= 'B' && ch[i] <= 'Z' )
                        consonant++;
        }

        cout << "Vowel : " << vowel << endl;
        cout << "Consonant : " << consonant << endl;

        return 0;
}
