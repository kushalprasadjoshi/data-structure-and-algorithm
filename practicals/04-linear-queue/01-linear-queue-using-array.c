// Implementation of Linear queue using array

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int linear_queue[MAX];
int r = -1, f = -1;

int is_empty() { return r == -1 && f == -1; }

int is_full() { return r == MAX - 1; }

void enqueue(int value) {
  if (is_full()) {
    printf("\nQueue overflow...");
    return;
  } else if (is_empty()) {
    r = r + 1;
    f = f + 1;
  } else {
    r = r + 1;
  }
  linear_queue[r] = value;
  printf("\n%d is enqueued successfully.", linear_queue[r]);
}

void dequeue() {
  if (is_empty()) {
    printf("\nQueue Underflow...");
    return;
  } else if (r == f) {
    printf("\n%d is dequeued successfully.", linear_queue[f]);
    r = -1;
    f = -1;
  } else {
    printf("\n%d is dequeued successfully.", linear_queue[f]);
    f++;
  }
}

void display() {
  int i;
  if (is_empty()) {
    printf("\nQueue is empty.");
  } else {
    printf("\nThe elements in the queue are: ");
    for (i = f; i <= r; i++) {
      printf("%d\t", linear_queue[i]);
    }
  }
}

int main() {
  int choice, data;
  while (1) {
    printf("\nEnter: \n\t1. for Enqueue \n\t2. for Dequeue \n\t3. for Display \n\t4. for "
           "Exit: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      if (!is_full()) {
        printf("\nEnter data: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      } else {
        printf("\nQueue overflow...");
      }
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("\nInvalid Choice...");
    }
  }
  return 0;
}
