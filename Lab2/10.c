/*You are given a linked list containing n elements. Your task is to perform the following operations:
1. Sort the linked list in descending order.
2. Print the i-th largest element from the sorted linked list.
If the value of i is larger than the number of elements in the linked list, print NULL.

Input:
1. The first line contains an integer n representing the number of elements in the linked list.
2. The second line contains n integers which are the elements of the linked list.
3. The third line contains an integer k representing the position of the element to find (i.e., the k-th largest element).

Constraints:
1 <= n <= 100
1 <= k <= n
The linked list elements are integers.

Output:
Print the k-th largest element from the sorted linked list.
Note: If k is larger than the number of elements in the linked list, print NULL.

Sample Test Cases:
Test Case 1:
Input:
5
10 5 20 15 30
3
Output:
15

Test Case 2:
Input:
4
2 4 1 3
2
Output:
3

Test Case 3:
Input:
5
1 2 3 4 5
6
Output:
NULL*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to perform Bubble Sort on the linked list in descending order
void bubbleSort(struct Node* head) {
    if (!head) return;
    int swapped;
    struct Node *ptr, *lptr = NULL;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr) {
            // For descending order, swap if current < next
            if (ptr->data < ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Function to find the k-th largest element in the linked list
struct Node* findKthLargest(struct Node* head, int k) {
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }
    return (current != NULL && count == k) ? current : NULL;
}

int main() {
    int n, i, k;
    struct Node* head = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Insert the nodes
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