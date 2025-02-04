/*Write a program to implement a circular queue of non negative integers using singly  linked list and print from (second element from head, similar to index= 1 in arrays) to first element.
Stopping criteria: user inputs -1

Input:
3 4 7 8 -1
Output:
4 7 8 3


Assume queue input is never empty
Retain duplicates*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void enqueue(Node **front, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if (*front == NULL)
    {
        *front = *rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = *front;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void printQueue(Node *front)
{
    if (front == NULL)
        return;
    if (front->next == front)
    {
        printf("%d\n", front->data);
        return;
    }
    Node *curr = front->next;
    while (curr != front)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", front->data);
}

int main()
{
    Node *front = NULL, *rear = NULL;
    int num;

    while (scanf("%d", &num) == 1 && num != -1)
    {
        enqueue(&front, &rear, num);
    }

    printQueue(front);

    if (front)
    {
        Node *temp = front;
        Node *nextNode;
        do
        {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != front);
    }

    return 0;
}