#include <bits/stdc++.h>
using namespace std;

void findingDuplicates(int ar[], int n) {
        set < int > st;

        for ( int i = 0; i < n-1; i++ ) {
                if ( ar[i] == ar[i+1] )
                        st.insert(ar[i]);
        }

        cout << "Duplicate elements are : ";
        for ( int x : st )
                cout << x << ", ";
        cout << endl;
}

int main()
{
        int ar[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingDuplicates(ar, n);

        return 0;
}
