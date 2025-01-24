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