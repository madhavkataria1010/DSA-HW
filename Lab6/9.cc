#include <bits/stdc++.h>
using namespace std;

int solution(string text) {
    unordered_map<char, int> freq;
    for (char ch: text)
        freq[ch]++;
    
    unordered_map<char, int> target = {
        {'d', 1}, {'a', 2}, {'t', 3}, {'s', 2},
        {'r', 2}, {'u', 2}, {'c', 1}, {'e', 1}
    };
    
    int ans = INT_MAX;
    for (auto &[ch, count]: target) {
        ans = min(ans, freq[ch] / count);
    }
    return ans;
}

int main() {
    string text;
    getline(cin, text); 

    int result = solution(text);
    cout << result << endl;

    return 0;
}