/*Given the root of a binary tree, determine if it is a valid Binary Search Tree (BST).

A Binary Search Tree (BST) is defined as follows:
The left subtree of a node contains only nodes with values less than the node's value.
The right subtree of a node contains only nodes with values greater than the node's value.
Both the left and right subtrees must also be binary search trees (i.e., the BST property holds for all nodes).

You just need to complete the isValid function. 

Input Format:
First Line: An integer n representing the number of elements in the BST.
Second Line: n space-separated integers representing the level-order traversal of the BST, where -1 represents NULL values (missing children).

Output Format:
The output is a boolean variable indicating whether the given tree is a BST or not.

Sample testcases:

Input:
   2
   / \
  1   4
     / 
    3   

Output: True
Explanation: The left child (1) is less than the root (2), and the right child (4) is greater than the root (2). Furthermore, the left child of (3) is less than the root (4). All subtrees are valid BSTs.

Input:
   5
   / \
  1   4
     / \
    3   6

Output: False
Explanation: The node with value 4 has a left child 3, but 4 is in the right subtree of 5, meaning all values in the right subtree should be greater than 5. Since 3 < 5, this is not a valid BST.*/



#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBST(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

bool validate(TreeNode* node, long long minVal, long long maxVal) {
    if (!node)
        return true;
    if (node->val <= minVal || node->val >= maxVal)
        return false;
    return validate(node->left, minVal, node->val) &&
           validate(node->right, node->val, maxVal);
}

bool isValid(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    int n; 
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; 

    TreeNode* root = buildBST(arr);
    cout << (isValid(root) ? "1" : "0") << endl;

    return 0;
}