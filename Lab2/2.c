#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

    void printList(Node* head) {
        if(head == NULL) {
            printf("EMPTY\n");
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

int main() {
    Node* head = NULL;
    int n, val;

    if(scanf("%d", &n) != 1){
        printf("Invalid input\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        if(scanf("%d", &val) != 1){
            printf("Invalid input\n");
            return 1;
        }
        insertSorted(&head, val);
    }

    printList(head);

    Node* current = head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}