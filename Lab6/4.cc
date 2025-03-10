#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Swap two elements in the heap
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify up: maintain max-heap property after insertion
    void heapify_up(size_t index) {
        while(index > 0) {
            size_t parent = (index - 1) / 2;
            if(heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down: maintain max-heap property after extraction or update
    void heapify_down(size_t index) {
        size_t size = heap.size();
        while(true) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t largest = index;
            if(left < size && heap[left] > heap[largest])
                largest = left;
            if(right < size && heap[right] > heap[largest])
                largest = right;
            if(largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert an element into the priority queue
    void push(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    // Extract the element with the highest priority
    int pop() {
        if(heap.empty())
            return -1;
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty())
            heapify_down(0);
        return top;
    }

    // Decrease the priority of an element by d. If the new priority is <= 0, remove it.
    void decreasePriority(int value, int d) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if(heap[i] == value) {
                index = i;
                break;
            }
        }
        if(index == -1)
            return;

        heap[index] -= d;
        if(heap[index] <= 0) {
            int lastIndex = heap.size() - 1;
            if(index == lastIndex) {
                heap.pop_back();
            } else {
                heap[index] = heap[lastIndex];
                heap.pop_back();
                // After replacing, fix the heap from the modified index.
                if(index > 0 && heap[index] > heap[(index - 1) / 2])
                    heapify_up(index);
                else
                    heapify_down(index);
            }
        } else {
            // Since priority decreased, it might need to move down.
            heapify_down(index);
        }
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;

    // Vector to store outputs from pop operations
    vector<int> outputs;

    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            cin >> p;
            pq.push(p);
        } else if (op == 2) {
            outputs.push_back(pq.pop());
        } else if (op == 3) {
            int p, d;
            cin >> p >> d;
            pq.decreasePriority(p, d);
        }
    }
    
    // Print all outputs after processing all operations
    for (int out : outputs)
        cout << out << endl;
    
    return 0;
}