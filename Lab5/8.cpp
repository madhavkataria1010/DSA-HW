#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int data) { 
        val = data; 
        next = nullptr; 
    }
};

// Split the list into two halves using slow and fast pointers
ListNode* getMiddle(ListNode* head) {
    if (!head) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted lists and remove duplicates
ListNode* merge(ListNode* left, ListNode* right) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (left && right) {
        if (left->val < right->val) {
            if (tail == &dummy || tail->val != left->val) {
                tail->next = left;
                tail = tail->next;
            }
            left = left->next;
        } else if (right->val < left->val) {
            if (tail == &dummy || tail->val != right->val) {
                tail->next = right;
                tail = tail->next;
            }
            right = right->next;
        } else {
            // Both values are equal; add one and skip duplicates
            if (tail == &dummy || tail->val != left->val) {
                tail->next = left;
                tail = tail->next;
            }
            left = left->next;
            right = right->next;
        }
    }
    
    // Process remaining nodes from left list
    while (left) {
        if (tail == &dummy || tail->val != left->val) {
            tail->next = left;
            tail = tail->next;
        }
        left = left->next;
    }
    
    // Process remaining nodes from right list
    while (right) {
        if (tail == &dummy || tail->val != right->val) {
            tail->next = right;
            tail = tail->next;
        }
        right = right->next;
    }
    
    tail->next = nullptr;
    return dummy.next;
}

// Merge Sort for Linked List
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next)
        return head;
    
    // Find the middle node to split the list
    ListNode* mid = getMiddle(head);
    ListNode* half = mid->next;
    mid->next = nullptr;
    
    // Recursively sort both halves
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(half);
    
    // Merge the two sorted halves (removing duplicates)
    return merge(left, right);
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Create a linked list from user input
ListNode* createList(int n) {
    if (n <= 0) return nullptr;

    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}
int main() {
    int n;
    cin >> n;

    ListNode* head = createList(n);

    cout << "Original List: ";
    printList(head);

    // Sort the list
    head = mergeSort(head);

    cout << "Sorted List : ";
    printList(head);

    return 0;
}
