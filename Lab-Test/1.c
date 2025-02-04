#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
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

// Function to enqueue a node in the linked list
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {  
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to dequeue a node from the linked list
void dequeue(struct Node** front) {
    if (*front == NULL)
        return;
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

// Function to find the length of the longest consecutive sequence of 1s
int findLongestConsecutiveOnes(int n, int* arr) {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            enqueue(&front, &rear, 1);
            currentCount++;
        } else {
            if (currentCount > maxCount)
                maxCount = currentCount;
            while (front != NULL) {
                dequeue(&front);
            }
            rear = NULL;  
            currentCount = 0;
        }
    }
    
    if (currentCount > maxCount)
        maxCount = currentCount;
    while (front != NULL) {
        dequeue(&front);
    }
    
    return maxCount;
}

int main() {
    int n;

    // Input the number of elements in the binary array
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    // Input the binary array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the length of the longest consecutive sequence of 1s
    int result = findLongestConsecutiveOnes(n, arr);
    printf("%d\n", result);

    // Free allocated memory
    free(arr);

    return 0;
}


//