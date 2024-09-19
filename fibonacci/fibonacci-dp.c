#include <stdio.h>

#define MAX 1000

int fib[MAX];

//  fibonacci using memoization (DP)
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    if (fib[n] != -1) { 
        return fib[n];
    }

    
    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}


int isInFibonacci(int num) {
    int i = 0;
    int fibNum;

    while (1) {
        fibNum = fibonacci(i);
        if (fibNum == num) {
            return 1;
        } else if (fibNum > num) {
            return 0;
        }
        i++;
    }
}

int main() {
    int num;

    for (int i = 0; i < MAX; i++) {
        fib[i] = -1;
    }

    printf("Informe um número: ");
    scanf("%d", &num);

    if (isInFibonacci(num)) {
        printf("O número %d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("O número %d NÃO pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}