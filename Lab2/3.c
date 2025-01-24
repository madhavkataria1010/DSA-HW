#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Global head and tail pointers
Node* head = NULL;
Node* tail = NULL;

// Function to append a node at the end of the list
void appendNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode){
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to print the doubly linked list
void printList() {
    if (head == NULL){
        printf("EMPTY\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to check and modify the list to be a palindrome if necessary
int isPalindrome() {
    if (head == NULL){
        // An empty list is considered a palindrome
        return 1;
    }
    Node* left = head;
    Node* right = tail;
    int is_palindrome = 1;
    
    while(left != right && left->prev != right){
        if(left->data != right->data){
            is_palindrome = 0;
            right->data = left->data; // Modify to make it a palindrome
        }
        left = left->next;
        right = right->prev;
    }
    return is_palindrome;
}

int main() {
    int n, val;

    // Read the number of elements
    if(scanf("%d", &n) !=1){
        printf("Invalid input\n");
        return 1;
    }

    // Read each element and append to the list
    for(int i =0; i < n; i++){
        if(scanf("%d", &val) !=1){
            printf("Invalid input\n");
            return 1;
        }
        appendNode(val);
    }

    // Check if the list is a palindrome and modify if necessary
    int is_palindrome = isPalindrome();

    if(is_palindrome){
        printf("Yes\n");
    }
    else{
        printf("No\n");
        printList();
    }

    // Free allocated memory
    Node* current = head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}