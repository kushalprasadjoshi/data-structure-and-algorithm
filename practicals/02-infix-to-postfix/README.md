# Lab 02: Infix to Postfix Conversion

## Algorithm
1. Scan the characters form left to right.

2. If the scanned character is '('
    - Push to the stack.  

3. If the scanned character is a character is an operand
    - Add to the postfix string.

4. If the scanned character is an operand
    - Check precendence:
        - If the precendence of the scanned character is greater than the precedence of the operator in the stack then push the operator to the stack.
        - Else pop the operator from the stack and add the popped operator to the postfix string. Then push the scanned operator on to the stack.

5. If the scanned character is ')'
    - Pop all the operators inside the parenthesis '()' and add it to postfix string.

---

## Experiment
```c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  char arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, char value) {
    if(isFull(s)) exit(printf("Stack overflow!\n"));
    s->arr[++s->top] = value;
}

char pop(Stack *s) {
    if(isEmpty(s)) exit(printf("Stack underflow!\n"));
    return s->arr[s->top--];
}

char peek(Stack *s) {
    if(isEmpty(s)) exit(printf("Stack is empty!\n"));
    return s->arr[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack myStack;
    initialize(&myStack);
    int i = 0, j= 0;

    while(infix[i] != '\0') {
        if (isdigit(infix[i]) || isalpha(infix[i])) postfix[j++] = infix[i];
        else if (infix[i] == '(') push(&myStack, '(');
        else if(infix[i] == ')') {
            while (!isEmpty(&myStack) && peek(&myStack) != '(') postfix[j++] = pop(&myStack);
            if (!isEmpty(&myStack) && peek(&myStack) == '(') pop(&myStack); // Discard the '('
        } else { // Operator
            while (!isEmpty(&myStack) && precedence(infix[i]) <= precedence(peek(&myStack))) postfix[j++] = pop(&myStack);
            push(&myStack, infix[i]);
        }
        i++;
    }
    while (!isEmpty(&myStack)) postfix[j++] = pop(&myStack);
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
```

**Output:**
```output
Enter infix expression: 2*6+9/(9+5)-7
Postfix expression: 26*995+/+7-
```

---
