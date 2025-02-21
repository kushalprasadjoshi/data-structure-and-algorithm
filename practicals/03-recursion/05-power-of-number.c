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
