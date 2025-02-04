/*Problem Statement 

Given the root of a binary  search tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Note: You first need to build the binary search tree (BST) by inserting nodes one by one. After constructing the BST, you should perform a level order traversal starting from the root node. The input should be the root of the BST, not an array.

Input Format:
First Line: An integer n representing the number of elements in the BST.
Second Line: n space-separated integers representing the elements to be inserted into the BST in the given order.

Output Format:
The output is a list of list  representing the level order traversal of the BST.

Example:

        4
       / \
      2   6
     / \  / \
    1   3 5  7

Input -
7
4 2 6 1 3 5 7

Output-

The above tree is provided the output expected is 
[[4], [2, 6], [1, 3, 5, 7]]*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node in BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Function to build BST from input array
TreeNode* buildBST(const vector<int>& arr) {
    TreeNode* root = nullptr;
    for (int val : arr)
        root = insertBST(root, val);
    return root;
}

// Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(level);
    }
    
    return result;
}

void printVector(const vector<vector<int>>& levels) {
    cout << "[";
    for (size_t i = 0; i < levels.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < levels[i].size(); j++) {
            cout << levels[i][j];
            if (j != levels[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != levels.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; 

    TreeNode* root = buildBST(arr);
    vector<vector<int>> result = levelOrder(root);
    printVector(result);

    return 0;
}
