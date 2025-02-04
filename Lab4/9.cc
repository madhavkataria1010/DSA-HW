/*Problem Statement:
Given a Binary Search Tree (BST), find the deepest rightmost node in the tree. The deepest rightmost node is the node that appears farthest from the root in terms of depth and is the rightmost node at that depth.

Input Format:
The first line contains an integer n, representing the number of nodes in the BST.
The second line contains n space-separated integers, representing the values to be inserted into the BST in the given order.

Output Format:
Print the value of the deepest rightmost node in the BST.*/


#include <iostream>
#include <queue>
using namespace std;

// Definition of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) { // Write your code here.
    }
};

// Function to insert a node into BST
Node* insert(Node* root, int data) { // Write your code here.
    if (root == nullptr)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to find the deepest rightmost node
int getDeepestRightmost(Node* root) { // Write your code here.
    if (!root)
        return -1;
    
    queue<Node*> q;
    q.push(root);
    Node* node = nullptr;
    
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    
    return node->data;
}

// Main function
int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << getDeepestRightmost(root) << endl;

    return 0;
}

