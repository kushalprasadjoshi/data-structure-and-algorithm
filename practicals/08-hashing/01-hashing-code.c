#include <stdio.h>

#define SIZE 10

int hashFunction(int data) { return data % SIZE; }

int main(int argc, char const *argv[])
{
    int key, index, hashTable[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEnter key: ");
        scanf("%d", &key);

        index = hashFunction(key);
        hashTable[index] = key;

        printf("%d is inserted successfully", key);
    }
    
    return 0;
}
