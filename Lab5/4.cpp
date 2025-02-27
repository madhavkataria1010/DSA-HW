/*Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Representation of input binary search tree

              5
             / \
            4   6
           /     \
          3       7
         /
        1
*/

// C++ code to find minimum value in BST
// using inorder traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder traversal to update minimum value
void inorder(Node* root, int &minVal) {
    if (root == nullptr)
        return;
    inorder(root->left, minVal);
    if (root->data < minVal)
        minVal = root->data;
    inorder(root->right, minVal);
}

int main() {

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);
    
    int minVal = INT_MAX;
    inorder(root, minVal);
    cout << minVal << endl;
    
    return 0;
}