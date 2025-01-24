#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;
    
    for(int i = 0; i <= n; i++) {
        if (first == NULL) return head;
        first = first->next;
    }
    
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    
    struct ListNode* temp = second->next;
    second->next = second->next->next;
    free(temp);
    
    return dummy.next;
}

void printList(struct ListNode* head) {
    // Write your logic here
    struct ListNode* current = head;
    while(current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* createList(int* arr, int size) {
    // Write your logic here
    if(size == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;
    for(int i = 1; i < size; i++) {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return head;
}

int main() {
    int n, sz;
    scanf("%d", &n);
    scanf("%d", &sz);
    int arr[sz];
    for (int i = 0; i < sz; i++) {
        scanf("%d", &arr[i]);
    }

    struct ListNode* head = createList(arr, sz);
    head = removeNthFromEnd(head, n);
    printList(head);

    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
