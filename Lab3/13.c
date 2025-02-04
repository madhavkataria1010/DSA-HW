/*Write a C program to delete the nth element of a queue.First it checks whether the queue is empty or not. Then it checks if the given position is valid or not. If the given position is valid, it deletes the first n-1 elements, then deletes the nth element by calling the dequeue() function.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return (q->front > q->rear);
}

void enqueue(Queue *q, int element)
{
    if (q->rear < MAX - 1)
    {
        q->rear++;
        q->arr[q->rear] = element;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        exit(1);
    }
    return q->arr[q->front++];
}

int size(Queue *q)
{
    return q->rear - q->front + 1;
}

void deleteNthElement(Queue *q, int pos)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    if (pos <= 0 || pos > size(q))
    {
        printf("Invalid position. The queue has %d elements.\n", size(q));
        return;
    }

    int temp;
    for (int i = 1; i < pos; i++)
    {
        temp = dequeue(q);
        enqueue(q, temp);
    }
    temp = dequeue(q);
    printf("Deleted element at position %d: %d\n", pos, temp);
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Original queue:\n");
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\n");

    int pos;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);

    deleteNthElement(&q, pos);

    printf("Updated queue:\n");
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\n");

    return 0;
}