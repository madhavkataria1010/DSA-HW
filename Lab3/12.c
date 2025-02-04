/*Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:

1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in another Queue.

Input : Queue[] = { 5, 1, 2, 3, 4 }
Output: Yes
Pop the first element of the given Queue, i.e. 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to
second Queue.
Now, pop element 5 in the stack and push it to the second Queue.

Input: Queue[] = { 5, 1, 2, 6, 3, 4 }
Output: No
Push 5 to stack.
Pop 1 and 2 from a given Queue and push them to another Queue.
Pop 6 from the given Queue and push to stack.
Pop 3 and 4 from the given Queue and push to the second Queue.
Now, from using any of the above operations, we cannot push 5
into the second Queue because it is below the 6 in the stack.

Observe that the second Queue (which will contain the sorted element) takes inputs (or enqueue elements) either from a given Queue or Stack. So, the next expected (initially 1) must be present as a front element of a given Queue or top element of the Stack. So, simulate the process for the second Queue by initializing the expected element as 1. Check if we can get the expected element from the front of the given Queue or from the top of the Stack. If we cannot take it from either of them, pop the front element of the given queue and push it to the stack.

Also, observe that the stack must also be sorted at each instance, i.e. the element at the top of the stack must be the smallest in the stack. For example, let x > y, and then x will always be expected before y. So, x cannot be pushed before y in the stack. Therefore, we cannot push an element with a higher value on top of the element with a lesser value.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(n)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue
{
    int items[MAX];
    int front, rear;
} Queue;

typedef struct Stack
{
    int items[MAX];
    int top;
} Stack;

void enqueue(Queue *q, int item)
{
    if (q->rear >= MAX - 1)
    {
        printf("Queue overflow!\n");
        exit(1);
    }
    q->items[++(q->rear)] = item;
}

int dequeue(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue underflow!\n");
        exit(1);
    }
    return q->items[(q->front)++];
}

void push(Stack *s, int item)
{
    if (s->top >= MAX - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

int pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

bool check_sortable(int arr[], int n)
{
    Queue inputQueue;
    inputQueue.front = 0;
    inputQueue.rear = -1;
    for (int i = 0; i < n; i++)
    {
        enqueue(&inputQueue, arr[i]);
    }

    Stack s;
    s.top = -1;

    int expected = 1;

    while (inputQueue.front <= inputQueue.rear || s.top != -1)
    {
        if (inputQueue.front <= inputQueue.rear && inputQueue.items[inputQueue.front] == expected)
        {
            dequeue(&inputQueue);
            expected++;
        }
        else if (s.top != -1 && s.items[s.top] == expected)
        {
            pop(&s);
            expected++;
        }
        else if (inputQueue.front <= inputQueue.rear)
        {
            int x = inputQueue.items[inputQueue.front];
            if (s.top == -1 || x < s.items[s.top])
            {
                push(&s, x);
                dequeue(&inputQueue);
            }
            else
            {
                return false;
            }
        }
        else
        {
            break;
        }
    }

    return (expected == n + 1);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX)
    {
        printf("Invalid input size.\n");
        return 0;
    }

    int arr[MAX];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            return 0;
        }
    }

    if (check_sortable(arr, n))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}