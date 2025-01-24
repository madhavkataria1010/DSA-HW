/*Given an array of elements, insert all the elements in a Linked List in sorted order. The insertion function should be called everytime you add an element to the linked list and it should be implemented in such a way that the inserted element goes to its correct position in the sorted order.
NOTE : You must NOT sort the array and then create a Linked List.

Input Format :
First line of the input contains an integer ‘n’, representing the size of the input array.
Next line contains n integers representing the elements in the array.

Output Format :
Print the elements in the sorted linked list.

Sample Test Case:
Input:
5 
3 11 9 16 15

Output:
3 9 11 15 16
*/
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