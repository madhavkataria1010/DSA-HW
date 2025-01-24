/*Given heads of two linked lists, concatenate the linked lists by connecting both of them. Connect the head of linked list 2 with the last node of linked list 1, i.e. concatenate the linked lists to create one big list. 

If both lists are NULL or 0, then the outcome should be EMPTY.

Input Format:
First line contains two integers n and m, the lengths of the two linked lists.
Second line contains n integers, values for linked list 1
Third line contains m integers, values for linked list 2

Output Format:
Print the resulting big linked list


Sample Test Case:
Input:
2 3
1 2
3 4 5

Output:
1 2 3 4 5 NULL
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a value into the linked list
void insert(Node** head, int val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(Node* head) {
    if(head == NULL) {
        printf("EMPTY\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
Node* concatenate(Node* head1, Node* head2) {
    if(head1 == NULL && head2 == NULL) return NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node* temp = head1;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    int n, m, a;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(&l1, a);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        insert(&l2, a);
    }

    Node* bigList = concatenate(l1, l2);
    printLinkedList(bigList);

    return 0;
}