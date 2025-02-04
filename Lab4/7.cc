/*You are given a binary tree in the form of an array.
A height-balanced binary tree is a binary tree where the height difference between the left and right subtrees of any node is at most one
Return 'true' if it is a height-balanced binary tree. Your task is to first construct a Binary Tree and then check whether it is a height-balanced tree or not.

Note:
The input tree is given in level order.
Null is represented by -1 in the input
The height of a tree is the maximum number of nodes in a path from the node to the leaf node.

Inputs : 
First line of input is the number of elements in tree including null
Second line of input contains all the elements

Sample Input 1:
11
1 2 3 4 -1 -1 -1 -1 5 -1 -1

Expected Answer:
false


Sample Input 2:
11
1 2 3 4 -1 -1 5 -1 -1 -1 -1

Expected Answer:
true*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        
        // left child
        if(i < arr.size()){
            if(arr[i] != -1){
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;
        }
        
        // right child
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

int checkHeight(Node* root) {
    if (!root) return 0;
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    return (checkHeight(root) != -1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++){
        cin >> nodes[i];
    }
    
    Node* root = buildTree(nodes);
    cout << (isBalanced(root) ? "true" : "false") << "\n";
    
    return 0;
}