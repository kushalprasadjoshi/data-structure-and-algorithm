#include <stdio.h>

long factorialOfNumber(int n) {
  if (n == 0)
    return 1;
  return n * factorialOfNumber(n - 1);
}

int main(int argc, char const *argv[]) {
  int num;
  long result;

  printf("\nEnter a number: ");
  scanf("%d", &num);

  result = factorialOfNumber(num);
  printf("The factorial of number %d is %ld", num, result);

  return 0;
}