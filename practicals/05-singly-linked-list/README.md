# Lab 05: Singly Linked List

## Singly Linked List
It is a simplest type of linked list in which every node contains some data and a pointer to the next node of same data type. The node contains a pointer to the next node means that the node stores the address of the next node in the sequence.

A singly linked list allows the traversal of data only in one direction.
```c
struct Node {
    int data;
    struct Node * next;
};
```

![Singly Linked List](/assets/singly-linked-list.png "Diagram of singly linked list")

---

## Experiment
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;
Node *head = NULL;

void push(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  printf("\n%d data is pushed", newNode->data);
}

int pop() {
  if (head == NULL)
    return (printf("\nStack Underflow!"));
  Node *ptr = head;
  head = head->next;
  printf("\n%d is popped", ptr->data);
  free(ptr);
}

int display() {
  if (head == NULL)
    return (printf("\nStack is empty."));
  printf("\nThe data are as follows: ");
  Node *ptr = head;
  while (ptr != NULL) {
    printf("\t%d", ptr->data);
    ptr = ptr->next;
  }
}

int main(int argc, char const *argv[]) {
  int data, choice;

  while (1) {
    printf(
        "\nEnter:\n\t1 for push\n\t2 for pop\n\t3 for display\n\t4 for exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data: ");
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(printf("Program exited successfully."));
    default:
      printf("Wrong input");
      break;
    }
  }

  return 0;
}
```

**Output:**
```output

Enter:
        1 for push
        2 for pop
        3 for display
        4 for exit
1
Enter the data: 23

23 data is pushed
Enter:
        1 for push
        2 for pop
        3 for display
        4 for exit
1
Enter the data: 56

56 data is pushed
Enter:
        1 for push
        2 for pop
        3 for display
        4 for exit
3

The data are as follows:        56      23
Enter:
        1 for push
        2 for pop
        3 for display
        4 for exit
2

56 is popped
Enter:
        1 for push
        2 for pop
        3 for display
        4 for exit
4
Program exited successfully.
```

---

## Conclusion
The stack can be created using both array list and linked list. This time it is created using linked list. When an stack is created using linked list we have two choices to follow its principle either from the end or the begining.

When the stack is created with operation at the end we need a linear traversal `O(n)` which takes a complexity in time mangaement. So, the operations were done at begining to avoid time complexity problems.

---
