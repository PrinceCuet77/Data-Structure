#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

int hashKey(int key) {
        return key % SIZE; // Returning specific index of key
}

int probe(int h[], int key) {
        int index = hashKey(key); // Where key should be

        int i = 0;
        while ( h[(index + i * i) % SIZE] != 0 ) // Finding free space
                i++;

        return (index + i * i) % SIZE;
}

int Search(int h[], int key) {
        int index = hashKey(key);

        int i = 0;
        while ( h[(index + i * i) % SIZE] != key ) { // Searching for key
                if ( h[(index + i * i) % SIZE] == 0 )
                        return -1;
                i++;
        }

        return (index + i * i) % SIZE; // Returning the index where it found
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
        Insert(h, 23);
        Insert(h, 43);
        Insert(h, 13);
        Insert(h, 27);

        Display(h);

        // Search
        printf("key : 22 is found at %d\n", Search(h, 22));
        printf("key : 23 is found at %d\n", Search(h, 23));

        // If I want to delete element then I have to re-hashing. So deletion in linear probing is not allowed.
        // If deletion needed then re-hashing must be done after deletion.

        return 0;
}
