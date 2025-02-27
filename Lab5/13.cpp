/* Implement a priority queue using a max-heap.
The following operations are required:
Insertion: Add an element with a given priority to the priority queue. The priority is determined by the value itself.
Extraction: Remove and return the element with the highest priority (maximum priority in this case).

Example -
Input : The first line of input (n) represents the total number of operations to perform. Each subsequent line represents an operation, where: (1, p) indicates a push operation, inserting an element with value p into the priority queue. 2 indicates a pop operation, extracting and printing the maximum element from the priority queue.
7                    // total no of ops.
1 7                // 1 is for push operation and 7 is the value to be inserted.
1 3
2                  // pop operation which will result the maximum value.
1 12
2
1 6
2

Output
For each pop operation (2), print the value of the extracted element. If the priority queue is empty during a pop operation, print -1.
7
12
6
*/

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify_up(size_t index)
    {
        while (index > 0)
        {
            size_t parent = (index - 1) / 2;
            if (heap[index] > heap[parent])
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapify_down(size_t index)
    {
        size_t size = heap.size();
        while (true)
        {
            size_t largest = index;
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    void push(int value)
    {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    int pop()
    {
        if (heap.empty())
            return -1;

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapify_down(0);
        return top;
    }
};

int main()
{
    PriorityQueue pq;
    int n;
    cin >> n;

    vector<int> results;

    for (int i = 0; i < n; ++i)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int p;
            cin >> p;
            pq.push(p);
        }
        else if (op == 2)
        {
            int result = pq.pop();
            results.push_back(result);
        }
    }

    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}