#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    // Build a min heap with the first K elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i < K; i++) {
        minHeap.push(arr[i]);
    }
    
    // For remaining elements, if element is larger than top, remove top and add element
    for (int i = K; i < N; i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    
    // Extract all elements from heap into a vector
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Reverse to get descending order
    std::sort(result.begin(), result.end(), std::greater<int>());
    
    // Print output
    for (int i = 0; i < K; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}