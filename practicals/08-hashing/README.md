# Lab 08: Hashing

## Hashing

Hashing is a technique used to uniquely identify a specific object from a group of similar objects. It involves the use of a hash function to convert an input (or 'key') into a fixed-size string of bytes, typically a hash code. The output is usually a 'hash code' that is used to index a hash table holding the data or records.

### Hash Function

A hash function is a function that takes an input and returns a fixed-size string of bytes. The output is typically a 'hash code' that is used to index a hash table. A good hash function has the following properties:
- **Deterministic**: The same input will always produce the same output.
- **Fast computation**: The hash function should be able to return the hash code quickly.
- **Uniform distribution**: The hash codes should be uniformly distributed to avoid clustering.
- **Minimally affected by changes**: Small changes in the input should produce significantly different hash codes.

### Hash Table

A hash table is a data structure that implements an associative array, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

### Collision Handling

Since hash functions can produce the same hash code for different inputs (a collision), hash tables need a method to handle collisions. Common methods include:
- **Chaining**: Each bucket contains a linked list of elements that hash to the same index.
- **Open Addressing**: All elements are stored in the hash table itself. When a collision occurs, the algorithm searches for the next available slot.

## Applications of Hashing

Hashing is widely used in various applications, including:
- **Data retrieval**: Hash tables are used in databases and file systems to quickly locate a data record given its search key.
- **Cryptography**: Hash functions are fundamental to many cryptographic algorithms.
- **Caching**: Hashing is used to quickly locate data in cache memory.
- **Checksum algorithms**: Hash functions are used to detect data corruption.

Hashing is a powerful tool in computer science, providing efficient data retrieval and storage solutions.

---

## Linear Probing

Linear probing is a collision resolution method in open addressing hash tables. When a collision occurs, the algorithm searches for the next available slot in a sequential manner. If the hash table is full, it wraps around to the beginning of the table. The steps for linear probing are as follows:

1. Compute the hash code for the key.
2. Check the computed index in the hash table.
3. If the slot is empty, insert the key-value pair.
4. If the slot is occupied, move to the next slot and repeat step 3 until an empty slot is found.

Linear probing can lead to clustering, where a group of consecutive slots are occupied, which can degrade performance. To mitigate clustering, other probing techniques like quadratic probing or double hashing can be used.

### Example

Consider a hash table of size 10 and a hash function `h(k) = k % 10`. Insert the keys 12, 22, 32, and 42 using linear probing:

1. Insert 12: `h(12) = 2`, place 12 at index 2.
2. Insert 22: `h(22) = 2`, index 2 is occupied, place 22 at index 3.
3. Insert 32: `h(32) = 2`, indices 2 and 3 are occupied, place 32 at index 4.
4. Insert 42: `h(42) = 2`, indices 2, 3, and 4 are occupied, place 42 at index 5.

The resulting hash table:

| Index | 0 | 1 | 2  | 3  | 4  | 5  | 6 | 7 | 8 | 9 |
|-------|---|---|----|----|----|----|---|---|---|---|
| Value |   |   | 12 | 22 | 32 | 42 |   |   |   |   |

---

## Experiment 1
```c
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
```

**Output:**
```output
Enter key: 56
56 is inserted successfully
Enter key: 67
67 is inserted successfully
Enter key: 89
89 is inserted successfully
Enter key: 34
34 is inserted successfully
Enter key: 52
52 is inserted successfully
Enter key: 24
24 is inserted successfully
Enter key: 90
90 is inserted successfully
Enter key: 231
231 is inserted successfully
Enter key: 456
456 is inserted successfully
Enter key: 7890
7890 is inserted successfully
```

---

## Experiment 2
```c
#include <stdio.h>
#include <stdlib.h>

struct item {
    int key;
    int value;
};

struct hashtable_item {
    int flag; // 0: data does not exist, 1: data exists, 2: data existed at least once
    struct item* data;
};

struct hashtable_item* array;
int size = 0;
int max = 10;

void init_array() {
    for (int i = 0; i < max; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hashcode(int key) {
    return (key % max);
}

void insert(int key, int value) {
    int index = hashcode(key);
    int i = index;
    struct item* new_item = (struct item*)malloc(sizeof(struct item));
    if (new_item == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_item->key = key;
    new_item->value = value;

    while (array[i].flag == 1) {
        // Probe through the array until we find an empty space
        i = (i + 1) % max;
    }

    array[i].flag = 1;
    array[i].data = new_item;
    size++;
}

void display() {
    for (int i = 0; i < max; i++) {
        if (array[i].flag == 1) {
            printf("Index %d: Key=%d, Value=%d\n", i, array[i].data->key, array[i].data->value);
        } else {
            printf("Index %d: ~\n", i);
        }
    }
}

void remove_item(int key) {
    int index = hashcode(key);
    int i = index;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            array[i].flag = 2; // Mark as deleted
            free(array[i].data);
            array[i].data = NULL;
            size--;
            return;
        }
        i = (i + 1) % max;
    }
    printf("Key %d not found\n", key);
}

int main() {
    // Allocate memory for the hash table
    array = (struct hashtable_item*)malloc(max * sizeof(struct hashtable_item));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the hash table
    init_array();

    // Example usage: insert key-value pairs
    insert(42, 100);
    insert(52, 200);

    // Display the hash table
    printf("\nBefore removal\n");
    display();
    
    // Remove an item
    printf("\nAfter removal\n");
    remove_item(42);

    // Display the hash table after removal
    display();

    // Free allocated memory
    for (int i = 0; i < max; i++) {
        if (array[i].flag == 1) {
            free(array[i].data);
        }
    }
    free(array);

    return 0;
}
```

**Output:**
```output

Before removal
Index 0: ~
Index 1: ~
Index 2: Key=42, Value=100
Index 3: Key=52, Value=200
Index 4: ~
Index 5: ~
Index 6: ~
Index 7: ~
Index 8: ~
Index 9: ~

After removal
Index 0: ~
Index 1: ~
Index 2: ~
Index 3: Key=52, Value=200
Index 4: ~
Index 5: ~
Index 6: ~
Index 7: ~
Index 8: ~
Index 9: ~
```

---