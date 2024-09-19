#include <stdio.h>

int main() {
    int index = 13; // sum of the natural numbers from 1 to index
    int k = 0;
    int sum = 0;

    while (k < index) {
        k = k + 1;
        sum = sum + k;
    }

    printf("%d\n", sum);
}