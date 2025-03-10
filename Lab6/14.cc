#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findPairs(vector<int>& nums, int target) {
    unordered_map<int, int> indexMap; 
    vector<pair<int, int>> result;   

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (indexMap.find(complement) != indexMap.end()) {
            result.push_back({indexMap[complement], i});
        }

        indexMap[nums[i]] = i;
    }

    return result;
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " space-separated integers: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<pair<int, int>> pairs = findPairs(nums, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    } else {
        for (auto& p : pairs) {
            cout << "[" << p.first << ", " << p.second << "]" << endl;
        }
    }

    return 0;
}