#include <stdio.h>
#include <stdbool.h>

int current = 0;
int maxDivisors = 0;
int antiPrime = 0;

int getDivisors(int n) {
    if (n % 96 != 0) return 0;
    if (n % 192 != 0) return 0;
    if (n % 160 != 0) return 0;
    if (n % 320 != 0) return 0;
    int divisors = 1;
    for (int i = 1; i <= n/2; i++) if (n % i == 0) divisors++;
    return divisors;
}

int main() {
    for (int i = 2160; i < 10000000; i += 2160) {
        const int divisors = getDivisors(i);
        if (divisors > current/3) {
            current++;
            printf("anti-prime number found: %d (%d divisors)\n", i, getDivisors(i));
            if (divisors > maxDivisors) {
                antiPrime = i;
                maxDivisors = divisors;
            }
        }
    }
    printf("%d has the most divisors out of all numbers between 0 and 10000000 (%d divisors)\n", antiPrime, maxDivisors);
    return 0;
}
