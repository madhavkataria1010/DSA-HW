/*Given a singly linked list and an integer k, the task is to rotate the linked list to the left by k places.

The idea is to first convert the linked list to circular linked list, by updating the next pointer of the last node to the head of the linked list. Then traverse to the k th node and update the head of the linked list to the (k+1)th node. Finally break the loop by updating the next pointer of k th node to NULL.

Input Format:
First line: Size of the linked list
Second line: Enter the elements of the linked list
Third line: An integer k, to rotate the linked list by the number of position from the left side


Output Format:
Print the original linked list
Print the rotated linked list by k number of times.

Sample Test Case:
Input:
5
10 20 30 40 50
4

Output:
Original list: 10 -> 20 -> 30 -> 40 -> 50
Rotated list: 50 -> 10 ->  20 -> 30 -> 40

Explanation: After rotating the linked list to the left by 4 places, the 5th node, i.e node 50 becomes the head of the linked list and the next pointer of node 50 points to node 10.

Input:
4
10 20 30 40 
6

Output:
Original list: 10 -> 20 -> 30 -> 40
Rotated list: 30 -> 40 -> 10 -> 20

Explanation: After rotating the linked list to the left by 6 places (same as rotating by 2 places as (k % len) = (6 % 4 = 2)) , the 3rd node, i.e node 30 becomes the head of the linked list and next pointer of node 40 points to node 10.

[Expected Approach] By changing pointer of k th node – O(n) Time and O(1) Space*/

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