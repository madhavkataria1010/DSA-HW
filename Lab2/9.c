#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* rotateLeft(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 1;
    struct Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0) return head;

    // Make it circular
    tail->next = head;

    // Move to the (k)th node
    struct Node* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    struct Node* newHead = current->next;
    current->next = NULL;
    return newHead;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        struct Node* node = newNode(data);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int k;
    scanf("%d", &k);
    printf("Enter the size of the linked list: Enter the elements of the linked list: Enter the number of rotations (k): ");
    
    printf("Original List: ");
    printList(head);

    head = rotateLeft(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}