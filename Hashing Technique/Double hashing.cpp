#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

int hashKey(int key) {
        return key % SIZE; // Returning specific index of key
}

int hashKey2(int key) {
        int R = 7; // Nearest prime number of SIZE under SIZE
        return (R - (key % R));
}

int probe(int h[], int key) {
        int h1 = hashKey(key); // Where key should be
        int h2 = hashKey2(key);

       // cout << h1 << " " << h2 << endl;

        int i = 0;
        while ( h[(h1 + i * h2) % SIZE] != 0 ) // Finding free space
                i++;

        return (h1 + i * h2) % SIZE;
}

int Search(int h[], int key) {
        int h1 = hashKey(key);
        int h2 = hashKey2(key);

        int i = 0;
        while ( h[(h1 + i * h2) % SIZE] != key ) { // Searching for key
                if ( h[(h1 + i * h2) % SIZE] == 0 )
                        return -1;
                i++;
        }

        return (h1 + i * h2) % SIZE; // Returning the index where it found
}

void Insert(int h[], int key) {
        int index = hashKey(key);

        if ( h[index] != 0 )
                index = probe(h, key);

        h[index] = key;
}

void Display(int h[]) {
        printf("Hashing table : ");
        for ( int i = 0; i < SIZE; i++ )
                printf("%d ", h[i]);
        printf("\n");
}

int main()
{
        int h[10] = {0};

        // Display
        Display(h);

        // Insert (must be less or equal to SIZE)
        Insert(h, 5);
        Insert(h, 25);
        Insert(h, 15);
        Insert(h, 35);
        Insert(h, 95);

        Display(h);

        // Search
        printf("key : 25 is found at %d\n", Search(h, 25));
        printf("key : 23 is found at %d\n", Search(h, 23));

        // If I want to delete element then I have to re-hashing. So deletion in linear probing is not allowed.
        // If deletion needed then re-hashing must be done after deletion.

        return 0;
}
