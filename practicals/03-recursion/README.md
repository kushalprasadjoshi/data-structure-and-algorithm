# Lab 03: Recursion

## Recursion
- Recursion is a process by which a function calls itself repeatedly, until some specified condition has been specified.

- The process is used for repetative computation in which each action is stated in terms of a previous result.

### Principles of Recursion
1. Each time a function call itself it must be closer, in some sense to the solution.

2. There must be decision criterion for stopping the process of computation.

### Advantages Over Iteration
- less bulky code
- enhance code redability
- some problems are inheritancly recursive are solved more easier.

---

## Experiment 1
```c
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
```

**Output:**
```output
Enter a number: 34
The sum of natural numbers before 34 is 595
```

---

## Experiment 2
```c
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
```

**Output:**
```output
Enter a number: 7
The factorial of number 7 is 5040
```

---

## Experiment 3
```c
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
```

**Output:**
```output
Enter the number of terms: 9
0       1       1       2       3       5       8       13      21
```

---

## Experiment 4
```c
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
```

**Output:**
```output
Enter the number of discs: 3

Move disk 1 from O to D
Move disk 2 from O to I
Move disk 1 from D to I
Move disk 3 from O to D
Move disk 1 from I to O
Move disk 2 from I to D
Move disk 1 from O to D
```

---

## Experiment 5
```c
#include <stdio.h>

long power(int base, int exponent) {
    if(exponent == 0) return 1;
    return base * power(base, --exponent);
}

int main(int argc, char const *argv[])
{
    int base, exponent;

    printf("Enter base and exponent: ");
    scanf("%d%d", &base, &exponent);

    printf("%d^%d = %ld", base, exponent, power(base, exponent));

    return 0;
}
```

**Output:**
```output
Enter base and exponent: 5 3
5^3 = 125
```

---

## Conclusion
Some problems were solved using recursion which gives clear understanding of recursion and its uses.

---