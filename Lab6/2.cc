#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    vector<pair<char, int>> freqVec(freq.begin(), freq.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first; 
        }
        return a.second > b.second; 
    });
    
    string result;
    for (auto &p : freqVec) {
        result.append(p.second, p.first);
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << frequencySort(s) << endl;
    return 0;
}