/*Problem: Reverse an array using Stack
Examples:
Input: arr[] = { 10, 20, 30, 40, 50 } 
Output: 50 40 30 20 10 
Explanation: Reversing the array modifies arr[] to { 50, 40, 30, 20, 10 } Therefore, the required output is 50 40 30 20 10.
Input: arr[] = { 1 } 
Output: 1*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

void reverseArray(int arr[], int n) {
    struct Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    free(stack->array);
    free(stack);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size. Exiting program.\n");
        return 0;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        printf("Reversed array: ");

    reverseArray(arr, n);
    free(arr);
    return 0;
}