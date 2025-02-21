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