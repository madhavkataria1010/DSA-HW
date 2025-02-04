/*Implement the Heap Sort algorithm to sort an integer array in non-decreasing order. In addition to the sorted array, print the total number of swaps performed during the heap-building and sorting process. The first input integer indicates the number of elements, followed by the array elements. The output should include the sorted array and the total count of swaps.
Input Format:
The first line contains a single integer n, representing the number of elements in the array.
The second line contains n space-separated integers, which are the elements of the array.
Output Format:
The first line should print the sorted array in non-decreasing order.
The second line should print the total number of swaps performed during the heap sort process.
Sample input 
5
5 4 3 2 1 
Output:
1 2 3 4 5 
8

Input:
5
7 7 7 7 7 
Output:
7 7 7 7 7
4*/

#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
private:
    vector<int> arr;
    int swapCount;

    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            swapCount++;
            heapify(n, largest);
        }
    }

public:
    HeapSort(vector<int>& input) : arr(input), swapCount(0) {}

    void sort() {
        int n = arr.size();
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }
        
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            swapCount++;
            heapify(i, 0);
        }
    }

    const vector<int>& getSortedArray() const {
        return arr;
    }

    int getSwapCount() const {
        return swapCount;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    HeapSort heapSort(input);

    heapSort.sort();

    const vector<int>& sortedArray = heapSort.getSortedArray();
    for (size_t i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    cout << "\n";

    cout << heapSort.getSwapCount() << "\n";

    return 0;
}