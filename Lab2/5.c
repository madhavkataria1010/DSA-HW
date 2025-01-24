/*Problem:
Given two sorted linked lists of non-negative integers consisting of n and m nodes respectively. The task is to merge both of the lists and print the merged list. You do not have to take count input from the user. Your code should include feature to
Insert non-negative elements into the first linked list until the user enters “-1”.
Insert non-negative elements into the second linked list until the user enters “-1”.
Merge them resulting in a fully sorted linked list, retaining all duplicates.
Assume that input linked lists are always sorted.
Don't forget to consider edge cases!.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (!head)
        return newNode;
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    Node* merged = NULL;
    if (l1->data <= l2->data) {
        merged = l1;
        merged->next = mergeLists(l1->next, l2);
    }
    else {
        merged = l2;
        merged->next = mergeLists(l1, l2->next);
    }
    return merged;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int num;

    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        if (num < 0) {
            continue;
        }
        list1 = insertEnd(list1, num);
    }

    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        if (num < 0) {
            continue;
        }
        list2 = insertEnd(list2, num);
    }

    Node* mergedList = mergeLists(list1, list2);
    printList(mergedList);

    Node* temp;
    while (mergedList) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}