/*Find the number of distinct elements occurring in the intersection of two sorted arrays of size n and m. Example: a = [1,2,3,4,5,6,7,8,9] b = [4,5,6,7,8,9,4,5,6] have [4,5,6,7,8,9] as common. So the output will be 6. 
Input Format: - First line states the value of N and M. Followed by 2 lines with n and m elements respectively.

Example:
Input 
3 2
4 4 4
1 0 4
Output 
1

Explanation : 
Intersection array = [4], Hence size = 1*/

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int solve(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0, distinctCount = 0, lastVal = INT_MIN;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] == b[j]) {
                if (a[i] != lastVal) {
                    lastVal = a[i];
                    distinctCount++;
                }
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return distinctCount;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];

    solution sol;
    cout << sol.solve(a, b) << "\n";
    return 0;
}
