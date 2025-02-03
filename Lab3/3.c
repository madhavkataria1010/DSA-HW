/*
Using the stack concept, find the solution for the given string s containing just the characters '(', ')', '{', '}', '[' and ']', and determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
Constraints:
        1 <= s.length <= 104
        s consists of parentheses only '()[]{}'
        */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definition for Stack
typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->data = (char *)malloc(capacity * sizeof(char));
    if (!stack->data) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, char ch) {
    if (stack->top == stack->capacity - 1) {
        // optional: resize the stack if needed
        return;
    }
    stack->data[++(stack->top)] = ch;
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) return '\0';
    return stack->data[(stack->top)--];
}

// Function to get the top element of the stack without removing it
char peek(Stack *stack) {
    if (isEmpty(stack)) return '\0';
    return stack->data[stack->top];
}

// Helper function to check matching pairs
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Function to validate the parentheses string using stack
bool isValidString(const char *s) {
    int n = strlen(s);
    Stack *stack = createStack(n);
    if (!stack) return false;
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // If stack is empty or not matching, invalid string
            if (isEmpty(stack) || !isMatching(pop(stack), ch)) {
                free(stack->data);
                free(stack);
                return false;
            }
        }
    }
    bool valid = isEmpty(stack);
    free(stack->data);
    free(stack);
    return valid;
}

int main() {
    char s[105];
    if (scanf("%104s", s) != 1) {
        printf("Error reading input.\n");
        return 1;
    }
    
if (isValidString(s))
        printf("true\n");
    else
        printf("false\n");
    
    return 0;
}