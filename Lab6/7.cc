#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }
    
    int n = s.size();
    for(auto &p : freq){
        if(p.second > (n+1)/2){
            cout << "Impossible";
            return 0;
        }
    }
    
    priority_queue<pair<int, char>> maxHeap;
    for(auto &p : freq){
        maxHeap.push({p.second, p.first});
    }
    
    string result = "";
    pair<int, char> prev = {0, '#'};
    
    while(!maxHeap.empty()){
        auto curr = maxHeap.top();
        maxHeap.pop();
        result.push_back(curr.second);
        
        if(prev.first > 0){
            maxHeap.push(prev);
        }
        curr.first--;
        prev = curr;
    }
    
    cout << "Possible";
    return 0;
}