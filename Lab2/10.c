#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


// Function to perform Bubble Sort on the linked list in descending order
void bubbleSort(struct Node* head){
    if(head == NULL) return;
    bool swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while(ptr1->next != lptr){
            if(ptr1->data < ptr1->next->data){
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

// Function to find the k-th largest element in the linked list
struct Node* findKthLargest(struct Node* head, int k){
    struct Node* current = head;
    int count = 1;
    while(current != NULL && count < k){
        current = current->next;
        count++;
    }
    return current;
}
// Main function to drive the code
int main() {
    struct Node* head = NULL;
    int n, i, k;

    // Reading number of elements and elements themselves
    scanf("%d", &n);
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