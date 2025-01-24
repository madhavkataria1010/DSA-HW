#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node before a given position
void insertAtPosition(struct Node** head_ref, int pos, int data) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    struct Node* current = *head_ref;
    for (int i = 1; i < pos-1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        // Position is greater than the length of the list
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, pos, newData;
    
    // Total number of elements in the linked list
    scanf("%d", &n);
    if (n == 0) {
        head = NULL;
    } else {
        int value;
        scanf("%d", &value);
        head = createNode(value);
        struct Node* current = head;
        for (int i = 1; i < n; i++) {
            scanf("%d", &value);
            current->next = createNode(value);
            current = current->next;
        }
    }
    
    // Position to insert the new node
    scanf("%d", &pos);
    
    // Value of the new node to be inserted
    scanf("%d", &newData);
    
    insertAtPosition(&head, pos, newData);
    printList(head);
    
    return 0;
}