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
