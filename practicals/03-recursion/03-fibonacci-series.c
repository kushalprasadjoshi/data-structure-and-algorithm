#include <stdio.h>

int fib(int n, int a, int b) {
  if (n > 0) {
    printf("%d\t", a);
    fib(n - 1, b, a + b);
  }
}

int main(int argc, char const *argv[]) {
  int num;
  printf("Enter the number of terms: ");
  scanf("%d", &num);

  fib(num, 0, 1);

  return 0;
}