# Lab 07: Sorting Algorithms

## Bubble Sort
Bubble sort is a simplest sorting algorithm that works by repeatedly swapping of adjacent elements if they are in the wrong order.

This algorithm isnot suitable for large datasets as its average and worst time complexity is quite high.

---

## Merge Sort
Merge Sort is an algorithm which uses divide and conquer approach. It keeps on dividing the array into two parts until they cannot be divided further and thery are sorted and merged back together in sorted array.

---

## Experiment 1
```c
/*
Write a program to sort an array of integers using bubble sort algorithm.
*/

#include <stdio.h>

void bubble_sort(long[], long);

int main() {
    long array[100], n, c;

    printf("Enter number of elements: ");
    scanf("%ld", &n);

    printf("Enter %ld integers\n", n);
    for (c = 0; c < n; c++) {
        scanf("%ld", &array[c]);
    }

    bubble_sort(array, n);

    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++) {
        printf("%ld\n", array[c]);
    }
}

void bubble_sort(long list[], long n) {
    long c, d, t;

    for (c = 0; c < n - 1; c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d + 1]) {
                // Swapping
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}
```

**Output:**
```output
Enter number of elements: 9
Enter 9 integers
56 54 34 67 54 32 56 78 54    
Sorted list in ascending order:
32
34
54
54
54
56
56
67
78
```

---

## Experiment 
```c
/*
Write a program to sort an array of integers using merge sort algorithm.
*/

#include <stdio.h>

#define SIZE 10

int a[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[SIZE];

void merge(int low, int mid, int high) {
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2]) {
            b[i] = a[l1++];
        } else {
            b[i] = a[l2++];
        }
    }

    while (l1 <= mid) {
        b[i++] = a[l1++];
    }

    while (l2 <= high) {
        b[i++] = a[l2++];
    }

    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void merge_sort(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    } else {
        return;
    }
}

int main()
{
    int i;

    printf("List before sorting\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    merge_sort(0, SIZE - 1);

    printf("\nList after sorting\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
```

**Output:**
```output
List before sorting
10 14 19 26 27 31 33 35 42 44 
List after sorting
10 14 19 26 27 31 33 35 42 44
```

---

## Conclusion
In conclusion, Bubble Sort and Merge Sort are sorting algorithms with different characteristics and performance issues. Although conceptually simple and adequate for education purposes, bubble sort could be more effective for large datasets than merge sort as very large datasets can lead to stack overflow in merge sort.

---
