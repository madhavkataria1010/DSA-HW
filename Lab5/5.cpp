#include <iostream>
#include <algorithm>
using namespace std;

// Structure of an AVL Tree Node
struct Node {
    int data, height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1; // New node has height 1
        left = right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Function to perform right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a node into the AVL tree
Node* insert(Node* root, int data) {
    // Perform normal BST insertion.
    if (root == nullptr)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else 
        return root; // duplicate keys not inserted

    // Update the height of the node.
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get the balance factor.
    int balance = getBalanceFactor(root);

    // Case 1: Left Left
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Case 2: Right Right
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Case 3: Left Right
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to count nodes where height equals depth
void countHeightEqualsDepth(Node* root, int depth, int &count) {
    if (root == nullptr) return;
    
    // Calculate node's height in problem definition (number of edges to leaf)
    int nodeHeight = root->height - 1; 
    if (nodeHeight == depth)
        count++;

    countHeightEqualsDepth(root->left, depth + 1, count);
    countHeightEqualsDepth(root->right, depth + 1, count);
}

// Wrapper function
int countNodesWithEqualHeightAndDepth(Node* root) {
    int count = 0;
    countHeightEqualsDepth(root, 0, count);
    return count;
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

    cout << countNodesWithEqualHeightAndDepth(root) << endl;
    return 0;
}