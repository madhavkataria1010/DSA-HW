/*Write a program to implement a stack using a linked list. The stack should have operations like push(), pop(), top(), isEmpty(). 
Queries:
1 x will represent to push integer x to the stack
2 will represent to pop the top element
3 will represent to print the stack top
4 will represent to print the entire stack

Input Format:
Number of queries q
q lines representing the queries

For example:
Input:
5
1 10
1 20
3
2
4

5 indicates the number of queries
1 10 indicates push 10
1 20 indicates push 20
3 indicates print top element of the stack, which is 20
2 indicates pop the top element, that is, pop 20
4 indicates printing the entire stack

Note: Pop does not require printing the topmost element. You have to remove it. For an empty stack, you have to print "Stack is empty\n"*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* topNode;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct Stack* s) {
    return s->topNode == NULL;
}

void push(struct Stack* s, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = s->topNode;
    s->topNode = newNode;
}

void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = s->topNode;
    s->topNode = s->topNode->next;
    free(temp);
}

void top(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("%d\n", s->topNode->data);
    }
}

void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* curr = s->topNode;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int q, type, x;
    scanf("%d", &q);
    struct Stack s;
    s.topNode = NULL;
    
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            push(&s, x);
        } else if (type == 2) {
            pop(&s);
        } else if (type == 3) {
            top(&s);
        } else if (type == 4) {
            printStack(&s);
        }
    }
    return 0;
}