/*Problem:
Implement a queue using two stacks. The queue should support the following operations:
Enqueue an element into the queue.
Dequeue an element from the queue.

Input Format:
First line: An integer, n, representing the number of operations to perform.
Next n lines: Either:
1 x: Representing an enqueue operation where x is the integer to be enqueued into the queue.
2: Representing a dequeue operation to remove the front element from the queue.

Output Format:
For every dequeue operation (2), print the dequeued element. If the queue is empty and a dequeue is attempted, print -1.*/



#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int* arr;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmptyStack(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        // Optionally, you can implement dynamic resizing.
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmptyStack(stack))
        return -1; // indicates empty stack
    return stack->arr[stack->top--];
}

// Queue structure using two stacks
struct Queue {
    struct Stack* s1;
    struct Stack* s2;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->s1 = createStack(capacity);
    queue->s2 = createStack(capacity);
    return queue;
}

void enqueue(struct Queue* queue, int x) {
    push(queue->s1, x);
}

int dequeue(struct Queue* queue) {
    if (isEmptyStack(queue->s2)) {
        while (!isEmptyStack(queue->s1)) {
            int x = pop(queue->s1);
            push(queue->s2, x);
        }
    }
    int result = pop(queue->s2);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Create a queue with sufficient capacity
    struct Queue* queue = createQueue(100);
    
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        
        if (operation == 1) {
            int x;
            scanf("%d", &x);
            enqueue(queue, x);
        } else if (operation == 2) {
            int result = dequeue(queue);
            printf("%d\n", result == -1 ? -1 : result);
        }
    }
    
    return 0;
}