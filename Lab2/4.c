/*Problem:
You are given linked list. Your task is to determine whether the list contains a loop.
A loop exists if the last node of the linked list points back to any node within the list, creating a cycle.

Input Format:

The first line contains the number of nodes in the linked list.

The second line contains a space-separated list of integers, where each integer represents the data of a node in the linked list.

The third line contains an integer pos, which indicates the index (0-based) of the node where the tail’s next pointer should connect. If pos = -1, the tail’s next pointer is NULL.

Output Format:
Print true if a loop exists in the linked list.
Print false if no loop exists.

Sample Test Case:
Input:
5
1 2 3 4 5
2

Output:
true
*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in the linked list
int detectLoop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// Function to create a linked list from input and create a loop
struct Node *createLinkedList(int arr[], int n, int pos)
{
    struct Node *head = NULL, *tail = NULL, *loopNode = NULL;

    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = createNode(arr[i]);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        if (i == pos)
        {
            loopNode = newNode;
        }
    }

    if (tail != NULL && pos != -1)
    {
        tail->next = loopNode;
    }
    return head;
}

int main()
{
    int n;
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    // printf("Enter the linked list nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos;
    // printf("Enter the position of the loop : ");
    scanf("%d", &pos);

    // Create linked list and detect loop
    struct Node *head = createLinkedList(arr, n, pos);
    int result = detectLoop(head);

    // Print result
    if (result)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}