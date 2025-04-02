//Implement a recursive C function to compute the power of a number (e.g. x^n). Test it with x = 2, n = 5, trace the recursion stack

#include <stdio.h>

int power(int x, int n) {
    if (n == 0) 
      return 1;  // Base case: x^0 = 1
    return x * power(x, n - 1);
}

void traceRecursion(int x, int n) {
    if (n == 0) {
        printf("power(%d, %d) -> 1\n", x, n);
        return;
    }
    printf("power(%d, %d) -> %d * power(%d, %d)\n", x, n, x, x, n - 1);
    traceRecursion(x, n - 1);
}

int main() {
    int x = 2, n = 5;
    printf("Tracing recursion for %d^%d:\n", x, n);
    traceRecursion(x, n);

    int result = power(x, n);
    printf("\nResult: %d^%d = %d\n", x, n, result);
    return 0;
}
