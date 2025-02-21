#include <stdio.h>

int sumOfNaturalNumbers(int n) {
  if (n == 0)
    return 0;
  return n + sumOfNaturalNumbers(n - 1);
}

int main(int argc, char const *argv[]) {
  int num, result;

  printf("\nEnter a number: ");
  scanf("%d", &num);

  result = sumOfNaturalNumbers(num);
  printf("The sum of natural numbers before %d is %d", num, result);

  return 0;
}