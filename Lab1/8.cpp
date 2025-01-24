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
