/*Problem: Given a binary tree and a sum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. Return false if no such path can be found. 
Example: Input:
Suppose the tree is:
             10
           /    \
          8      2
        / \    /
       3   5  2

Output: True 
Explanation:  Root to leaf path sum, existing in this tree are:

10 -> 8 -> 3  =  21
10 -> 8 -> 5  = 23
10 -> 2 -> 2 = 14
So it is possible to get sum = 21
Hint: The idea is to recursively move to the left and right subtree and decrease sum by the value of the current node and if at any point the current node is equal to a leaf node and remaining sum is equal to zero then the answer is true.*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(Node *root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    int sum;
    cout << "Enter the sum to check: ";
    cin >> sum;

    cout << (hasPathSum(root, sum) ? "True" : "False") << endl;

    return 0;
}
