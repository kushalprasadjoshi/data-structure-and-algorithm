# Lab 01: Implement of Stack Using Array

## Theory
A stack is a fundamental data structure in computer science which operates in a LIFO (Last In First Out) principle. This means that the last element added to the stack will be first one to be removed.

### Fundamental Operations of Stack are:
1. **Push Operation:**
Adding an element to the stack is refered to as 'push'. When you push an item on to the stack, it becomes the new top of the stack.

2. **Pop Operation:**
Removing an element from the stack is refered to as 'pop'. When you pop an item from the stack, you are removing the current top item of the stack.

3. **Top/Peek:**
The top operation returns the current top elemeent of the stack. 'Peek' is another common term used for the same operation.

4. **IsEmpty:**
This operation checks if the stack is empty.

5. **IsFull:**
This operation checks if the stack is full.

---

## Experiment
```c
/*
Implementation of stack in C using array.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // Define macro

int stack[SIZE], top = -1; // Creating a stack

int isFull() { return top == SIZE - 1; } // Check whether the stack is full
int isEmpty() { return top == -1; }      // Check whether the stack is empty

void push(int value) { // Function to push element to stack
  if (isFull()) exit(printf("STACK OVERFLOW!"));
  printf("%d is pushed successfully.", stack[++top] = value);
}

int pop() { // Function to pop out elememnt from stack
  if (isEmpty()) exit(printf("STACK UNDERFLOW!"));
  return stack[top--];
}

void peek() { // Function to peek in the stack
  if (isEmpty()) exit(printf("STACK EMPTY!"));
  printf("%d is at top of the stack.", stack[top]);
}

void display() { // Function to display elements in stack
  if (isEmpty()) exit(printf("STACK IS EMPTY!"));
  printf("The elements in the stack are: ");
  for (int i = 0; i <= top; i++) printf("%d\t", stack[i]);
}

int main(int argc, char const *argv[]) {
  int choice, data;

  do {
    printf("\n\nEnter:\n\t1 for Push\n\t2 for Pop\n\t3 for Peek\n\t4 for display\n\t5 for Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      push(data);
      break;

    case 2:
      printf("%d is popped successfully.", pop());
      break;

    case 3:
      peek();
      break;

    case 4:
      display();
      break;

    case 5:
      exit(0);

    default:
      printf("INVALID CHOICE.");
    }
  } while (1);

  return 0;
}
```

**Output:**
```output

Enter:
        1 for Push
        2 for Pop
        3 for Peek
        4 for display
        5 for Exit
1
Enter data: 567
567 is pushed successfully.

Enter:
        1 for Push
        2 for Pop
        3 for Peek
        4 for display
        5 for Exit
1
Enter data: 453
453 is pushed successfully.

Enter:
        1 for Push
        2 for Pop
        3 for Peek
        4 for display
        5 for Exit
3
453 is at top of the stack.

Enter:
        1 for Push
        2 for Pop
        3 for Peek
        4 for display
        5 for Exit
4
The elements in the stack are: 567      453

Enter:
        1 for Push
453 is popped successfully.

Enter:
        1 for Push
        2 for Pop
        3 for Peek
        4 for display
        5 for Exit
5
```

---
