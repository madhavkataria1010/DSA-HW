/*You are given the number of nodes n in a binary tree, followed by two sequences of integers that represent the in-order and pre-order traversals of the tree. Your task is to:
Construct the binary tree from these two traversals.
Return (or print) the level-order traversal of the constructed tree.

Input Format:
An integer n, the number of nodes in the tree.
A line with n integers separated by spaces representing the in-order traversal.
A line with n integers separated by spaces representing the pre-order traversal.
Output Format:
The level-order traversal of the tree, printed as n space-separated integers.

Example
Input : 6
3 1 4 0 5 2
0 1 3 4 2 5
output: 0 1 2 3 4 5 */


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void printLevelOrder(Node *root) {
    if (root == nullptr) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

int searchInorder(vector<int> &inorder, int value, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; 
}

Node *buildTreeRecur(vector<int> &inorder, vector<int> &preorder, 
                     int &preIndex, int left, int right) {
    if (left > right)
        return nullptr;
    
    int curr = preorder[preIndex];
    Node *node = new Node(curr);
    preIndex++;

    if (left == right)
        return node;

    int pos = searchInorder(inorder, curr, left, right);
    node->left = buildTreeRecur(inorder, preorder, preIndex, left, pos - 1);
    node->right = buildTreeRecur(inorder, preorder, preIndex, pos + 1, right);
    return node;
}

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    int preIndex = 0;
    return buildTreeRecur(inorder, preorder, preIndex, 0, inorder.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // Build the tree
    Node *root = buildTree(inorder, preorder);

    // Print the tree in level order
    printLevelOrder(root);
    cout << "\n";

    return 0;
}