#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ERROR_MESSAGE_LENGTH 128
#define MAX_USAGE 5

typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS,
    EXPONENTIATION,
    SQUARE_ROOT,
    CUBE_ROOT,
    SINE,
    COSINE,
    TANGENT,
    NATURAL_LOGARITHM,
    BASE10_LOGARITHM
} Operation;

typedef struct {
    float num1;
    float num2;
} Numbers;

void printMenu() { 
    printf("Advanced Calculator\n");
    printf("--------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exponentiation\n");
    printf("7. Square Root\n");
    printf("8. Cube Root\n");
    printf("9. Sine\n");
    printf("10. Cosine\n");
    printf("11. Tangent\n");
    printf("12. Natural Logarithm\n");
    printf("13. Base-10 Logarithm\n");
    printf("Enter your choice (1-13): ");
}

void getNumbers(Numbers* numbers, int operation) {
    switch (operation) {
        case ADDITION:
        case SUBTRACTION:
        case MULTIPLICATION:
        case DIVISION:
        case MODULUS:
            printf("Enter first number : ");
            scanf("%f", &numbers->num1);
            printf("\n Enter second number : ");
            scanf("%f", &numbers->num2);
            break;
        case EXPONENTIATION:
            printf("Enter base and exponent : ");
            scanf("%f %f", &numbers->num1, &numbers->num2);
            break;
        case SQUARE_ROOT:
        case CUBE_ROOT:
        case SINE:
        case COSINE:
        case TANGENT:
        case NATURAL_LOGARITHM:
        case BASE10_LOGARITHM:
            printf("Enter a number: ");
            scanf("%f", &numbers->num1);
            numbers->num2 = 0.0;
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }
}

float performOperation(Numbers numbers, Operation operation) {
    float result = 0.0;
    switch (operation) {
        case ADDITION:
            result = numbers.num1 + numbers.num2;
            break;
        case SUBTRACTION:
            result = numbers.num1 - numbers.num2;
            break;
        case MULTIPLICATION:
            result = numbers.num1 * numbers.num2;
            break;
        case DIVISION:
            if (numbers.num2 != 0) {
                result = numbers.num1 / numbers.num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            break;
        case MODULUS:
            if (numbers.num2 != 0) {
                result = fmod(numbers.num1, numbers.num2);
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
                exit(1);
            }
            break;
        case EXPONENTIATION:
            result = pow(numbers.num1, numbers.num2);
            break;
        case SQUARE_ROOT:
            if (numbers.num1 >= 0) {
                result = sqrt(numbers.num1);
            } else {
                printf("Error: Square root of negative number is not allowed.\n");
                exit(1);
            }
            break;
        case CUBE_ROOT:
            if (numbers.num1 >= 0) {
                result = cbrt(numbers.num1);
            } else {
                printf("Error: Cube root of negative number is not allowed.\n");
                exit(1);
            }
            break;
        case SINE:
            result = sin(numbers.num1);
            break;
        case COSINE:
            result = cos(numbers.num1);
            break;
        case TANGENT:
            result = tan(numbers.num1);
            break;
        case NATURAL_LOGARITHM:
            if (numbers.num1 > 0) {
                result = log(numbers.num1);
            } else {
                printf("Error: Natural logarithm of non-positive number is not allowed.\n");
                exit(1);
            }
            break;
        case BASE10_LOGARITHM:
            if (numbers.num1 > 0) {
                result = log10(numbers.num1);
            } else {
                printf("Error: Base-10 logarithm of non-positive number is not allowed.\n");
                exit(1);
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }
    return result;
}

int main() {
    int choice;
    Numbers numbers;
    float result;
    int usage = 0;

    while (usage < MAX_USAGE) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getNumbers(&numbers, ADDITION);
                result = performOperation(numbers, ADDITION);
                break;
            case 2:
                getNumbers(&numbers, SUBTRACTION);
                result = performOperation(numbers, SUBTRACTION);
                break;
            case 3:
                getNumbers(&numbers, MULTIPLICATION);
                result = performOperation(numbers, MULTIPLICATION);
                break;
            case 4:
                getNumbers(&numbers, DIVISION);
                result = performOperation(numbers, DIVISION);
                break;
            case 5:
                getNumbers(&numbers, MODULUS);
                result = performOperation(numbers, MODULUS);
                break;
            case 6:
                getNumbers(&numbers, EXPONENTIATION);
                result = performOperation(numbers, EXPONENTIATION);
                break;
            case 7:
                getNumbers(&numbers, SQUARE_ROOT);
                result = performOperation(numbers, SQUARE_ROOT);
                break;
            case 8:
                getNumbers(&numbers, CUBE_ROOT);
                result = performOperation(numbers, CUBE_ROOT);
                break;
            case 9:
                getNumbers(&numbers, SINE);
                result = performOperation(numbers, SINE);
                break;
            case 10:
                getNumbers(&numbers, COSINE);
                result = performOperation(numbers, COSINE);
                break;
            case 11:
                getNumbers(&numbers, TANGENT);
                result = performOperation(numbers, TANGENT);
                break;
            case 12:
                getNumbers(&numbers, NATURAL_LOGARITHM);
                result = performOperation(numbers, NATURAL_LOGARITHM);
                break;
            case 13:
                getNumbers(&numbers, BASE10_LOGARITHM);
                result = performOperation(numbers, BASE10_LOGARITHM);
                break;
            default:
                printf("Error: Invalid choice.\n");
                return 1;
        }

        printf("Result: %.2f\n", result);
        usage++;
    }

    printf("You have reached the maximum usage of %d times.\n", MAX_USAGE);
    return 0;
}
