#include <stdio.h>

void TOH(int n, char A, char B, char C) {
  if (n > 0) {
    TOH(n - 1, A, C, B);
    printf("\nMove disk %d from %c to %c", n, A, B);
    TOH(n - 1, C, B, A);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  printf("Enter the number of discs: ");
  scanf("%d", &n);

  TOH(n, 'O', 'D', 'I');

  return 0;
}

