#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in the linked list 
int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// Function to create a linked list from input and create a loop 
struct Node* createLinkedList(int arr[], int n, int pos) {
    struct Node *head = NULL, *tail = NULL, *loopNode = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        if (i == pos) {
            loopNode = newNode;
        }
    }

    if (tail != NULL && pos != -1) {
        tail->next = loopNode;
    }
    return head;
}

int main() {
    int n;
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    // printf("Enter the linked list nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos;
    // printf("Enter the position of the loop : ");
    scanf("%d", &pos);

    // Create linked list and detect loop
    struct Node* head = createLinkedList(arr, n, pos);
    int result = detectLoop(head);

    // Print result
    if (result) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}