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

