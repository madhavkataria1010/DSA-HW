/*Write a C++ program to implement Heapsort. Your program should take an integer input from the user, followed by the respective number of integers to be sorted. Additionally, implement a function to find the k-th smallest element in the sorted array.*/


#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;      // left = 2*i + 1
    int right = 2 * i + 2;     // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heapsort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to find k-th smallest element (array must be sorted in ascending order)
int findKthSmallest(int arr[], int n, int k) {
    // k-th smallest is at index k-1 if 1 <= k <= n
    if (k < 1 || k > n)
        return -1; // Error indicator
    return arr[k - 1];
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamically allocate an array of n integers
    int* arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k to find the k-th smallest element: ";
    cin >> k;

    heapSort(arr, n);

    // Output: Sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Output: kth smallest element
    int kthSmallest = findKthSmallest(arr, n, k);
    if (kthSmallest == -1)
        cout << "Invalid k value.\n";
    else
        cout << "The " << k << "-th smallest element is: " << kthSmallest << "\n";

    // Free the allocated memory
    delete[] arr;
    return 0;
}