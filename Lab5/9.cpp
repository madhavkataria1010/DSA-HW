/*Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
The algorithm must run in O(N log N) time complexity.


Input Format:
       The first line contains an integer N (size of the array).
        The second line contains N space-separated integers representing the array elements.
Output Format:
       Print a single integer: the inversion count of the array.

Sample Test Case:
6
8 4 2 1 3 5

Output
9*/


#include <iostream>
#include <vector>

using namespace std;

long mergeCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    long invCount = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            invCount += (leftArr.size() - i);
        }
    }
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
    
    return invCount;
}

long mergeSortCount(vector<int>& arr, int left, int right) {
    long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortCount(arr, left, mid);
        invCount += mergeSortCount(arr, mid + 1, right);
        invCount += mergeCount(arr, left, mid, right);
    }
    return invCount;
}

int inversionCount(vector<int>& arr) {
    return mergeSortCount(arr, 0, arr.size() - 1);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << inversionCount(arr) << endl;
    return 0;
}