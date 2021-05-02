#include <stdio.h>
#include <stdbool.h>

int current = 0;
int maxDivisors = 0;
long abundantNumber = 0;

int getDivisors(long n) {
    int divisors = 14;
    for (long l = 12; l <= n/4; l++) if (n % l == 0) divisors++;
    return divisors;
}

int main() {
    for (long l = 720720; l < 50000000; l += 720720) {
        const int divisors = getDivisors(l);
        if (divisors > current/3) {
            current++;
            printf("anti-prime number found: %ld (%d divisors)\n", l, divisors);
            if (divisors > maxDivisors) {
                abundantNumber = l;
                maxDivisors = divisors;
            }
        }
    }
    printf("%ld has the most divisors out of all numbers between 0 and 50000000 (%d divisors)\n", abundantNumber, maxDivisors);
    return 0;
}
