#include <bits/stdc++.h>
using namespace std;

void findingMissedElements(int ar[], int n) {
        set < int > st;
        int firstElement = ar[0];
        for ( int i = 0; i < n; i++ ) {
                st.insert(ar[i]);
                firstElement = min(firstElement, ar[i]);
        }

        cout << "Missed values are : ";
        for ( int x : st ) {
                if ( firstElement != x ) {
                        while ( firstElement != x ) {
                                cout << firstElement << ", ";
                                firstElement++;
                        }
                }
                firstElement++;
        }
        cout << endl;
}

int main()
{
        int ar[] = {3, 7, 4, 13, 12, 6, 1, 11, 2, 10};
        int n = sizeof(ar) / sizeof(ar[0]);
        findingMissedElements(ar, n);

        return 0;
}
