/*Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Inputs : 
First line of input is the number of elements in tree including null
Second line of input contains all the elements
Third line of input is the targetSum.

Constraints:
1 <= nodeVal <= 1000

Sample Input 1:
11
3 1 9 -1 -1 6 10 -1 -1 -1 -1
4

Sample Output 1:
true


Sample Input 2:
9
2 1 4 -1 -1 3 -1 -1 -1
11

Sample Output 2:
false*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<int>& arr) {
    if(arr.empty() || arr[0] == -1) return nullptr;
    
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    
    while(!q.empty() && i < arr.size()){
        Node* current = q.front();
        q.pop();

        if(i < arr.size()){
            if(arr[i] != -1){
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;
        }

        if(i < arr.size()){
            if(arr[i] != -1){
                current->right = new Node(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

bool hasPathSum(Node* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) {
        return targetSum == root->val;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }
    
    int targetSum;
    cin >> targetSum;
    
    Node* root = buildTree(nodes);
    cout << (hasPathSum(root, targetSum) ? "true" : "false") << "\n";
    
    return 0;
}