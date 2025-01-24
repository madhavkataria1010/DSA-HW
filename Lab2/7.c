#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get the length of the linked list
int getLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to get the node at a specific position
struct Node* getNodeAt(struct Node* head, int position) {
    struct Node* current = head;
    int index = 1;
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }
    return current;
}

// Function to perform binary search on a sorted linked list
int binarySearch(struct Node* head, int key) {
    int left = 1;
    int right = getLength(head);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        struct Node* midNode = getNodeAt(head, mid);
        if (midNode == NULL) {
            return -1;
        }
        if (midNode->data == key) {
            return mid;
        } else if (midNode->data < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Function to append a node to the linked list
struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to create a linked list from an array
struct Node* createList(int* arr, int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        head = appendNode(head, arr[i]);
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    int n, key;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    head = createList(arr, n);

    scanf("%d", &key);

    printf("%d\n", binarySearch(head, key));

    return 0;
}