/*Given a list of unique integer values, construct a Binary Search Tree (BST) by inserting nodes in the given order. Once the BST is built, determine the longest path from the root to a leaf node.
- If multiple paths have the same length, only the first found longest path should be printed.
- The path should be printed in order from root to leaf.
- The program must use a stack implemented via a linked list to traverse the tree and find the longest path.

Input Format
The first line contains an integer N (1<=N<=1000), representing the number of nodes.
The second line contains N space-separated integers, representing the node values in the order they should be inserted into the BST.

Output Format
Print the first longest path found from the root to a leaf node.
The output should be in the format: X -> Y -> Z, where X, Y, and Z are nodes in the longest path.

Example Test Cases

Test Case 1
Input:
6  
5 3 8 1 4 7  
Output:
5 -> 3 -> 1

Test Case 2
Input:
10
10 5 15 3 7 20 2 13 12 11
Output:
10 -> 15 -> 13 -> 12 -> 11*/


#include <iostream>
#include <vector>
using namespace std;

// Node structure for BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    bool visited;
    
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
        visited = false;
    }
};

// Stack Node structure (Linked List implementation)
struct StackNode {
    TreeNode* treeNode;
    vector<int> path;  // Store path to this node
    StackNode* next;

    StackNode(TreeNode* node, vector<int> currentPath) {
        treeNode = node;
        path = currentPath;
        next = nullptr;
    }
};

// Stack implementation using Linked List
class Stack {
private:
    StackNode* top;
public:
    Stack() { 
        top = nullptr; 
    }

    void push(TreeNode* node, vector<int> currentPath) {
        StackNode* newNode = new StackNode(node, currentPath);
        newNode->next = top;
        top = newNode;
    }

    StackNode* pop() {
        if(isEmpty())
            return nullptr;
        StackNode* temp = top;
        top = top->next;
        return temp;
    }

    bool isEmpty() {
        return (top == nullptr);
    }
};

// Function to insert node in BST
TreeNode* insert(TreeNode* root, int data) {
    if(root == nullptr) {
        return new TreeNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the first longest path from root to leaf using a stack (DFS)
void findLongestPath(TreeNode* root) {
    if(root == nullptr)
        return;
        
    Stack stack;
    vector<int> initialPath;
    initialPath.push_back(root->data);
    stack.push(root, initialPath);
    
    vector<int> longestPath;
    
    while(!stack.isEmpty()){
        StackNode* current = stack.pop();
        TreeNode* node = current->treeNode;
        vector<int> currentPath = current->path;
        
        if(node->left == nullptr && node->right == nullptr) {
            if(currentPath.size() > longestPath.size()){
                longestPath = currentPath;
            }
        }
        if(node->right) {
            vector<int> newPath = currentPath;
            newPath.push_back(node->right->data);
            stack.push(node->right, newPath);
        }
        if(node->left) {
            vector<int> newPath = currentPath;
            newPath.push_back(node->left->data);
            stack.push(node->left, newPath);
        }
        delete current;
    }
    
    // Print the longest path
    for (size_t i = 0; i < longestPath.size(); i++) {
        cout << longestPath[i];
        if(i != longestPath.size()-1)
            cout << " -> ";
    }
    cout << endl;
}

// Driver code
int main() {
    TreeNode* root = nullptr;
    int n, value;
    
    if(!(cin >> n)) {
        cout << "NULL" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    
    findLongestPath(root);
    
    return 0;
}