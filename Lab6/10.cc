#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int maxLen = 0, start = 0;
    for (int i = 0; i < s.size(); i++) {
        start = max(start, lastIndex[s[i]] + 1);
        maxLen = max(maxLen, i - start + 1);
        lastIndex[s[i]] = i;
    }
    return maxLen;
}

int main() {
    string s;
    getline(cin, s);

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}