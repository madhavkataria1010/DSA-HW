/*Problem : You are given a queue containing n elements and an integer K. Your task is to reverse the first K elements of the queue while leaving the rest of the queue unchanged. If K is greater than or equal to n, reverse the entire queue.

Input Format:
An integer n representing the number of elements in the queue.
A space-separated sequence of integers representing the elements of the queue (if n > 0).
An integer K representing the number of elements to reverse.

Output Format:
If the queue is empty (n = 0), print "Empty Queue".
Otherwise, print the queue after reversing the first K elements.

Sample 1
input:
10
10 20 30 40 50 60 70 80 90 100
5

output:
50 40 30 20 10 60 70 80 90 100

Sample 2

input:
0

output:
Empty Queue*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int *items;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->capacity = 1000; // initial capacity
    q->items = (int *)malloc(q->capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return (q->size == 0);
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (q->size >= q->capacity) {
        q->capacity *= 2;
        q->items = (int *)realloc(q->items, q->capacity * sizeof(int));
    }
    q->items[q->size++] = value;
    q->rear = q->size - 1;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    q->size--;
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = -1;
    }
    return value;
}

// Function to reverse the first K elements of a queue
void reverseQueueFirstKElements(int K, Queue* q) {
    if (K > q->size) {
        K = q->size;
    }
    int i = 0, j = K - 1;
    while(i < j) {
        int temp = q->items[q->front + i];
        q->items[q->front + i] = q->items[q->front + j];
        q->items[q->front + j] = temp;
        i++;
        j--;
    }
}

// Function to display the queue without a trailing space (modified queue)

// Function to display the original queue with a space after each element,
// including after the last element.
void printOriginalQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty Queue\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}


// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty Queue\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    Queue q;
    initQueue(&q);
    int n, value, K;

    // Read the number of elements to add to the queue
    // printf("Enter the number of elements to add to the queue: ");
    scanf("%d", &n);


    // Read and enqueue elements to the queue
    // printf("Enter the elements to add to the queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    // Read the value of K (number of elements to reverse)
    // printf("Enter the number of elements to reverse (K): ");
    scanf("%d", &K);

    // Display the original queue
    printf("Original Queue: ");
    displayQueue(&q);

    // Reverse the first K elements
    reverseQueueFirstKElements(K, &q);

    // Display the queue after reversal
    printf("Queue after reversing  elements: ");
    displayQueue(&q);

    return 0;
}