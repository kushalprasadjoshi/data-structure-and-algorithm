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
