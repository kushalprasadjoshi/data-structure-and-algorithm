# Lab 04: Linear Queue Implementation Using Array

## Linear Queue ADT
- A linear data structure that follows FIFO principle.
- Two pointers front and rear keep track of the start and end of the queue.
- Time Complexity:
    - Search = O(n)
    - Insert = O(1)
    - Delete = O(1)

![Linear Queue Example](https://clipart-library.com/2023/isometric-queue-composition-with-people-standing-waiting-line-atm_1284-63729.jpg "Real world example of a linear queue.")

### Initialization
- There are various ways to initialize a queue.
- We are considering the following conditions to initialize a queue.
    - rear = -1
    - front = 0

![Initialization of Linear Queue](/assets/linear-queue.png "Digram that shows the initialization of linear queue.")

- For above conditions:
    - Queue full --> rear = MAX - 1
    - Queue empty --> front > rear

### Enqueue
Step 1: Start  
Step 2: Check if the queue is full i.e. rear = MAX - 1  
Step 3: If the queue is full then, display an appopirate message such as queue overflow.  
Step 4: Else increase the rear and insert the data in the rear position.  
Step 5: Stop  

### Dequeue
Step 1: Start  
Step 2: Check if the queue is empty i.e. front > rear  
Step 3: If the queue is empty then, display appopirate message such as queue underflow.  
        Else delete the element and increase the front.  
Step 4: Stop

---

## Experiment 
```c
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
```

**Output:**
```output

Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 1

Enter data: 34

34 is enqueued successfully.
Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 1

Enter data: 56

56 is enqueued successfully.
Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 1

Enter data: 78

78 is enqueued successfully.
Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 2

34 is dequeued successfully.
Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 3

The elements in the queue are: 56       78
Enter:
        1. for Enqueue
        2. for Dequeue
        3. for Display
        4. for Exit: 4
```

---
