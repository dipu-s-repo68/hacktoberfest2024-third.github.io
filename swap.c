#include <stdio.h>

void swap(int *a, int *b) {
    // Swap using arithmetic operations
    if (a != b) {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

int main() {
    int x, y;
    printf("Enter the first number: ");
    scanf("%d", &x);

    printf("Enter the second number: ");
    scanf("%d", &y);

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
