/*Given the root of a Binary Search Tree (BST), write a function that returns the minimum absolute difference between the values of any two different nodes in the tree.

Input Format:
The input is given as a list representing the level-order traversal of the Binary Search Tree (BST).
Each element in the list represents a node's value, and the keyword null is used to indicate the absence of a node (i.e., a missing child).
Output Format:
The output is a single integer representing the minimum absolute difference between the values of any two different nodes in the BST.

Sample Input 1
[4,2,6,1,3]
Sample Output 1
1

Sample Input 2
[1,0,48,null,null,12,49]
Sample Output 2
1*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* buildTreeFromTokens(const vector<string>& tokens) {
    if (tokens.empty() || tokens[0] == "null")
        return nullptr;
    
    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    
    while(!q.empty() && i < tokens.size()){
        Node* current = q.front();
        q.pop();
        
        // Left Child
        if(i < tokens.size()){
            if(tokens[i] != "null"){
                current->left = new Node(stoi(tokens[i]));
                q.push(current->left);
            }
            i++;
        }
        
        // Right Child
        if(i < tokens.size()){
            if(tokens[i] != "null"){
                current->right = new Node(stoi(tokens[i]));
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

void inorderTraversal(Node* root, int &prev, bool &first, int &minDiff) {
    if(!root) return;
    inorderTraversal(root->left, prev, first, minDiff);
    if(!first) {
        minDiff = min(minDiff, root->val - prev);
    } else {
        first = false;
    }
    prev = root->val;
    inorderTraversal(root->right, prev, first, minDiff);
}

int minDiffInBST(Node* root) {
    int prev = 0;
    bool first = true;
    int minDiff = numeric_limits<int>::max();
    inorderTraversal(root, prev, first, minDiff);
    return minDiff;
}

int main(){

    string input;
    getline(cin, input);

    if(!input.empty() && input.front() == '[')
        input = input.substr(1, input.size()-2);
    
    vector<string> tokens;
    stringstream ss(input);
    string token;
    while(getline(ss, token, ',')){
        size_t start = token.find_first_not_of(" ");
        size_t end = token.find_last_not_of(" ");
        if(start != string::npos && end != string::npos)
            token = token.substr(start, end - start + 1);
        tokens.push_back(token);
    }
    
    Node* root = buildTreeFromTokens(tokens);
    cout << minDiffInBST(root) << "\n";
    
    return 0;
}