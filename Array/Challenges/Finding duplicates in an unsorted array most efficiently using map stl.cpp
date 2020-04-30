#include <bits/stdc++.h>
using namespace std;

void findingDuplicates(int ar[], int n) {
        map < int, int > mp;
        for ( int i = 0; i < n-1; i++ ) {
                mp[ar[i]]++;
        }

        cout << "Duplicates are : ";
        for ( auto x : mp ) {
                if ( x.second > 1 )
                        cout << x.first << ", ";
        }
        cout << endl;
}

int main()
{
        int ar[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingDuplicates(ar, n);

        return 0;
}
