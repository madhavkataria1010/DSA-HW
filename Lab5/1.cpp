/*
WAP to implement the insertion of nodes into an AVL tree and check whether the resulting tree is a valid AVL tree. 
Your main program should take the following input:
The number of nodes n to be inserted into the AVL tree. n integers representing the data of each node to be inserted.

Inputs: number of nodes and value of nodes.
Output: root node of resultant and "True " or "False" to represent validity.

input:
3
2 1 3
output :
2 1 3 
True
*/
#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (!node)
        return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to create a new AVL tree node
Node* createNode(int data) {
    return new Node(data);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    if (!N)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* node, int data) {
    // Standard BST insertion
    if (node == nullptr)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Duplicate keys not allowed
        return node;

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node* root) {
    if (!root)
        return true;

    int balance = getBalance(root);
    if (balance > 1 || balance < -1)
        return false;

    return isValidAVL(root->left) && isValidAVL(root->right);
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } 
    else {
        cout << "False" << endl;
    }

    return 0;
}