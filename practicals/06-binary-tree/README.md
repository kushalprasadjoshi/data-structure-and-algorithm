# Lab 06: Binary Tree

## Binary Tree Traversals

### Preorder Traversal
- Visit the node.
- Do preorder traversal of left sub tree.
- Do preorder traversal of right sub tree.

### Postorder Traversal
- Do a post-order traversal of the left sub tree.
- Followed by a pre-order traversal of right sub tree.
- Visit the node.

### Inorder Traversal
- Do an inorder traversal of the left sub tree.
- Visit the node.
- Finish with an inorder traversal of the right sub tree.

---

## Experiment
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int item;
  struct Node *left;
  struct Node *right;
} Node;

// Inorder traversal
void inorderTraversal(Node *root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d -> ", root->item); 
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

// Create a new node
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

// Insert on left of the node
Node* insertLeft(Node* root, int value) {
    root->left = createNode(value);
    return root->left;
}

// Insert on right of the node
Node* insertRight(Node* root, int value) {
    root->right = createNode(value);
    return root->right;
}


int main() {
    Node* root = createNode(1);

    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    printf("\nInorder Traversal: ");
    inorderTraversal(root);

    printf("\nPreorder Traversal: ");
    preorderTraversal(root);

    printf("\nPostorder Traversal: ");
    postorderTraversal(root);

    return 0;
}
```

**Output:**
```output
Inorder Traversal: 5 -> 12 -> 6 -> 1 -> 9 -> 
Preorder Traversal: 1 -> 12 -> 5 -> 6 -> 9 ->
Postorder Traversal: 5 -> 6 -> 12 -> 9 -> 1 ->
```

---

## Conclusion
Using a C-program we create the following binary tree.


![Binary Tree](/assets/binary-tree.png "The binary tree we have created during experiment.")

**Inorder Traversal:** 5, 12, 6, 1, 9  
**Preorder Traversal:** 1, 12, 5, 6, 9  
**Postorder Traversal:** 5, 6, 12, 9, 1

In the program, we get an exact output as we have got from the classical methods of the tree traversal. So, the tree traversal is possible with the help of recursion.

---
