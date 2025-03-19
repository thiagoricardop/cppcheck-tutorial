#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int x = 10, y = 5;
    int result;
    
    result = add(x, y);
    printf("Addition: %d\n", result);
    
    result = subtract(x, y);
    printf("Subtraction: %d\n", result);
    
    result = multiply(x, y);
    printf("Multiplication: %d\n", result);
    
    result = divide(x, y);
    printf("Division: %d\n", result);
    
    // Intentional errors for Cppcheck testing
    int uninitialized_var;
    printf("Uninitialized variable: %d\n", uninitialized_var); // Uninitialized variable
    
    int arr[5];
    arr[10] = 50; // Out-of-bounds access
    
    return 0;
}
