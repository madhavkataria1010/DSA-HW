#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node *head = NULL, *tail = NULL;

// Add a node at the end
void addNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert in the middle
void addInMid(int data) {
    if (!head) { // If list is empty
        addNode(data);
        return;
    }
    // Count nodes
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }

    int mid;
    if (count % 2 == 0) {
        mid = count / 2 - 1;
    } else {
        mid = count / 2;
    }
    temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // Insert after temp
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Display the list
void display() {
    printf("Updated List: \n");
    Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value;

    // Read the number of elements to add to the list
    scanf("%d", &n);

    // Read and add nodes to the list
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        addNode(value);
    }

    // Read the value to be added in the middle
    scanf("%d", &value);

    addInMid(value);  // Add the new node in the middle
    display();        // Display the updated list

    return 0;
}