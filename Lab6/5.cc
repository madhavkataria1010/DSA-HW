#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to partition the array
int partition(vector<pair<int, int>> &employees, int low, int high) {
    auto pivot = employees[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((employees[j].second > pivot.second) || 
            (employees[j].second == pivot.second && employees[j].first < pivot.first)) {
            i++;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[i + 1], employees[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<pair<int, int>> &employees, int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);
        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;  // Number of employees

    vector<pair<int, int>> employees(N);
    for (int i = 0; i < N; i++) {
        cin >> employees[i].first >> employees[i].second;  // Employee ID and Salary
    }

    // Call Quick Sort function
    quickSort(employees, 0, N - 1);

    // Output the sorted employees
    for (auto &emp : employees) {
        cout << emp.first << " " << emp.second << endl;
    }

    return 0;
}