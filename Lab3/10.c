/*Write a C program to evaluate a postfix mathematical expression. The program should validate the input, compute the result, and handle errors gracefully.

Requirements:
1. The postfix expression will contain positive integers and the operators +, -, *, /.
2. Numbers and operators in the input expression will be separated by spaces. Example: 5 1 2 + 4 * + 3 -
3. The program should evaluate the expression step-by-step and return the final result.

Input Constraints:
1. Input will consist of valid positive integers and operators only.
2. Operators supported:
   A. + (Addition)
   B. - (Subtraction)
   C. * (Multiplication)
   D. / (Integer Division)
2. Invalid input includes:
   A. Any character other than digits, operators, or spaces.
   B. Division by zero.
   C. Malformed expressions (e.g., operators without sufficient operands).
Output:
1. If the input is valid, print the evaluated result.
2. If the input is invalid, print Invalid input.

Sample Test Cases:
Example1:
Input:
5 1 2 + 4 * + 3 -
Output:
14

Example2:
Input:
4 2 8 $
Output:
Invalid input

Example3:
Input:
3 4 / 0 /
Output:
Invalid input*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char input[512];
    
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Invalid input\n");
        return 0;
    }
    
    int stack[MAX_SIZE];
    int top = -1;
    
    char *token = strtok(input, " \n");
    while (token != NULL) {
        if (isdigit(token[0])) {
            char *endptr;
            long num = strtol(token, &endptr, 10);
            if (*endptr != '\0') {
                printf("Invalid input\n");
                return 0;
            }
            if (top >= MAX_SIZE - 1) {
                printf("Invalid input\n");
                return 0;
            }
            stack[++top] = (int)num;
        }
        else if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (top < 1) {
                printf("Invalid input\n");
                return 0;
            }
            int b = stack[top--];
            int a = stack[top--];
            if (token[0] == '/' && b == 0) {
                printf("Invalid input\n");
                return 0;
            }
            int result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid input\n");
                    return 0;
            }
            stack[++top] = result;
        }
        else {
            printf("Invalid input\n");
            return 0;
        }
        token = strtok(NULL, " \n");
    }
    
    if (top != 0) {
        printf("Invalid input\n");
        return 0;
    }
    
    printf("%d\n", stack[top]);
    return 0;
}