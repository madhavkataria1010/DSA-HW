/*You are given a Binary Search Tree (BST)  and a target value. Your task is to implement an efficient search function in C++ that finds whether the target value exists in the BST or not. The search operation should have a time complexity of O(logn).
Input: First line contains Height of the BST , Second Line: Elements in the BST Third Line: An integer value key to search in the BST.
Output: Return 1 if the key exists in the BST, otherwise return 0.
Sample:
Input
2
4 2 6 1 3 5 7
3
Output
1
Constraints:
The BST follows the standard properties:
The left subtree of a node contains only nodes with values less than the node's value.
The right subtree of a node contains only nodes with values greater than the node's value.
Assume that all input trees are full binary trees and follow best case time complexity. In case of any other solutions like linear search, some test cases might time out.  Hint for number of elements: So if height is 2,  it means the full binary tree will have 7 elements*/



#include <iostream>
#include <cmath>  
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
   
}

bool searchBST(TreeNode* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->val == key) {
        return true;
    }
    if (key < root->val) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
 
}

int main() {
    int h, key;
    cin >> h;  

    int n = pow(2, h + 1) - 1;
    
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cin >> key; 

    cout << (searchBST(root, key) ? 1 : 0) << endl;

    return 0;
}