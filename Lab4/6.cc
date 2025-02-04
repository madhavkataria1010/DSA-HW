/*Two binary trees, “Tree-1" and “Tree-2”, where each node of the tree has a positive integer value. Merge them in a common binary tree.
Rules:
1. If two nodes overlap, the sum of their values should be the new value of the merged node and If either node in the overlapping position is null, the non-null node should be used as the value of the new node.
2. The binary tree contains only positive integer elements. -1 denotes a null node.
Input Format:
First line contains a single integer n, denoting the number of nodes in the 1st binary tree.
Second line contains the n integers, nodes of the 1st binary tree in level order.
Third line contains a single integer m, denoting the number of nodes in the 2nd binary tree.
Fourth line contains the m integers, nodes of the 2nd binary tree in level order.
Output Format:
Print the Inorder traversal of the merged binary tree.

input :
7
1 2 3 -1 4 -1 5
7
1 2 2 6 -1 7 -1

Output:
6 4 4 2 7 5 5*/

#include <iostream>
#include <vector>
#include <queue>
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

        // Left child
        if(i < arr.size()){
            if(arr[i] != -1){
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;
        }

        // Right child
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

Node* mergeTrees(Node* t1, Node* t2) {
    if (!t1 && !t2) return nullptr;
    
    if (!t1) return t2;
    if (!t2) return t1;
    
    Node* merged = new Node(t1->val + t2->val);
    merged->left = mergeTrees(t1->left, t2->left);
    merged->right = mergeTrees(t1->right, t2->right);
    return merged;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> tree1Nodes(n);
    for (int i = 0; i < n; i++){
        cin >> tree1Nodes[i];
    }
    
    int m;
    cin >> m;
    vector<int> tree2Nodes(m);
    for (int i = 0; i < m; i++){
        cin >> tree2Nodes[i];
    }
    
    Node* tree1 = buildTree(tree1Nodes);
    Node* tree2 = buildTree(tree2Nodes);
    
    Node* mergedTree = mergeTrees(tree1, tree2);
    
    inorder(mergedTree);
    cout << "\n";
    
    return 0;
}