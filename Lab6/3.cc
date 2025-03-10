#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

// Function to partition the array using Lomuto's partition scheme
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// QuickSelect function: returns the k-th smallest element in arr within indices left and right.
int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k);
}

int main()
{
    int N, K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> K;

    int kthSmallest = quickSelect(arr, 0, N - 1, K - 1);
    int kthLargest = quickSelect(arr, 0, N - 1, N - K);

    cout << kthSmallest << " " << kthLargest << endl;
    return 0;
}
