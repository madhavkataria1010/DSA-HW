#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to perform Bubble Sort on the linked list in descending order
void bubbleSort(struct Node* head) {
    if (!head) return;
    int swapped;
    struct Node *ptr, *lptr = NULL;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr) {
            // For descending order, swap if current < next
            if (ptr->data < ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Function to find the k-th largest element in the linked list
struct Node* findKthLargest(struct Node* head, int k) {
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }
    return (current != NULL && count == k) ? current : NULL;
}

int main() {
    int n, i, k;
    struct Node* head = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Insert the nodes
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Reading the value of k
    scanf("%d", &k);

    // Sorting the list in descending order using Bubble Sort
    bubbleSort(head);

    // Finding the k-th largest element
    struct Node* result = findKthLargest(head, k);

    // Print the result
    if (result != NULL) {
        printf("%d\n", result->data);
    } else {
        printf("NULL\n");
    }

    return 0;
}