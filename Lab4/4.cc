/*Problem Statement: Find the Kth Smallest Element in a Binary Search Tree
You are given a Binary Search Tree (BST) and an integer K. Your task is to find the Kth smallest element in the BST.
Input Format: An integer N, representing the number of nodes in the BST in first line,  A list of N space-separated integers, representing the BST in level order traversal in 2nd line and An integer K, representing the position (1-based index) of the smallest element to find in third line.
Output Format:
Print the Kth smallest element in the BST.

Example 1: Input:
7 
5 3 7 2 4 6 8 
3
Output: 4
Explanation:
The elements in sorted order: [2, 3, 4, 5, 6, 7, 8].
The 3rd smallest element is 4*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void inorder(Node* root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

int kthSmallest(Node* root, int k) {
    vector<int> sorted;
    inorder(root, sorted);
    return sorted[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Node* root = NULL;
    for(int i = 0; i < N; i++){
        int val;
        cin >> val;
        root = insertBST(root, val);
    }

    int K;
    cin >> K;
    cout << kthSmallest(root, K) << "\n";
    return 0;
}