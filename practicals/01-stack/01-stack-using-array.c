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
