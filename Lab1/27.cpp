#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    vector<int> vec;
public:
    Solution(int size, vector<int> a) {
        n = size;
        vec = a;
    }

    int give_ones() {
        int countRows = 0;
        for (int i = 0; i < n; i++) {
            int ones = __builtin_popcount(vec[i]);
            if (ones >= 5)
                countRows++;
        }
        return countRows;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    Solution s(n, a);
    cout << s.give_ones();

    return 0;
}