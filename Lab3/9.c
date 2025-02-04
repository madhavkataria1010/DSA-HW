/*Given an infix expression, Convert the given infix expression to prefix expression.
Note: Keep in mind order of precedence.
Examples:

Example 1:
Input: x+y*z/w+u
Output: ++x/*yzwu

Example 2:
Input: p+q
Output: +pq

Constraints:
1<= s.length<=30*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    return s->data[s->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
    }
    return -1;
}

void reverseString(char *str) {
    int i, j;
    char temp;
    int n = strlen(str);
    for(i = 0, j = n - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int i, k = 0;
    int len = strlen(infix);
    for(i = 0; i < len; i++) {
        char c = infix[i];
        if(isalnum(c)) {
            postfix[k++] = c;
        } else if(c == '(') {
            push(&s, c);
        } else if(c == ')') {
            while(!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            if(!isEmpty(&s))
                pop(&s); 
        } else if(isOperator(c)) {

            while(!isEmpty(&s) && isOperator(peek(&s)) &&
                  ((precedence(c) < precedence(peek(&s))) ||
                   (precedence(c) == precedence(peek(&s)) && c == '^'))) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while(!isEmpty(&s))
        postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

void infixToPrefix(char *infix, char *prefix) {
    char revInfix[MAX], revPostfix[MAX];
    strcpy(revInfix, infix);
    reverseString(revInfix);
    for (int i = 0; revInfix[i]; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }
    infixToPostfix(revInfix, revPostfix);
    strcpy(prefix, revPostfix);
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("%s\n", prefix);
    return 0;
}