#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};
void printList(Node* head);

Node* split(Node* head) {
    if (!head || !head->next)
        return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) { // second operand does not run if first  operand is false ie no segfault
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = nullptr; // break the link

    if (secondHalf)
        secondHalf->prev = nullptr;

    return secondHalf;
}

Node* merge(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->data <= second->data) {
        first->next = merge(first->next, second);
        if (first->next)
            first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        if (second->next)
            second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !(head->next))
        return head;

    Node* secondHalf = split(head);
    // printList(head);
    // printList(secondHalf);

    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    return merge(head, secondHalf);
}

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


int incrementDuplicates(Node* head){
    int count = 0;
    head = head->next;
    while(head){
        if(head->data <= head->prev->data){
            int prevVal = head->data;
            head->data = head->prev->data + 1;
            count += head->data - prevVal;
        }
        head = head->next;
    }
    return count;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int value = 1;
    
    Node* head = nullptr;
    while(value > 0){
        cin >> value;
        if(value <= 0)
            break;
        insert(head, value);
    }

    head = mergeSort(head);
    int count = incrementDuplicates(head);
    printList(head);
    cout << count;

    return 0;
}