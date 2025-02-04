/*You are given a binary search tree with N nodes, where each node contains a unique integer value. Your task is to traverse the tree in Preorder, Inorder, and Postorder and print the results. Use CPP/C++ Language to implement this task. 
Input Format
         The first line contains an integer N, the number of nodes in the tree.
         The next N lines contain three integers X, L, and R, where:
                X is the value of the node.
                L is the value of the left child (or -1 if there is no left child).
                R is the value of the right child (or -1 if there is no right child).
    [The given input represents a valid binary search tree with no cycles.]
Output Format
            Print three lines:
                    The first line should contain the Preorder traversal.
                    The second line should contain the Inorder traversal.
                    The third line should contain the Postorder traversal.
    [Each value should be space-separated.]*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, Node*> nodes;
    unordered_set<int> children;
    
    for (int i = 0; i < n; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        if (nodes.find(x) == nodes.end())
            nodes[x] = new Node(x);
        if (l != -1) {
            if (nodes.find(l) == nodes.end())
                nodes[l] = new Node(l);
            nodes[x]->left = nodes[l];
            children.insert(l);
        }
        if (r != -1) {
            if (nodes.find(r) == nodes.end())
                nodes[r] = new Node(r);
            nodes[x]->right = nodes[r];
            children.insert(r);
        }
    }
    
    Node* root = nullptr;
    for (auto &pair : nodes) {
        if (children.find(pair.first) == children.end()) {
            root = pair.second;
            break;
        }
    }
    
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    
    return 0;
}