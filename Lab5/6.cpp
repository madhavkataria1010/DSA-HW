/*Binary Tree to Binary Search Tree Conversion using STL set
Problem: Given a Binary Tree, the task is to convert it to a Binary Search Tree. The conversion must be done in such a way that it keeps the original structure of the Binary Tree.

Input:
	  10
        //   \\
       2       7
    //  \\
   8      4

Output:
	  8
        //  \\
        4    10
     // \\
   2    7

Explanation: The above Binary tree is converted to a Binary Search tree by keeping the original structure of the Binary Tree.

Approach:
The idea is to traverse the binary tree recursively and insert the value of nodes into a hash set. Then, traverse the tree in an in-order manner, and pop the smallest value from the set and update the value of the node to the popped value.

Copy the items of the binary tree in a set while doing inorder traversal. This takes O(n log n) time. Note that set in C++ STL is implemented using a Self Balancing Binary Search Tree like Red Black Tree, AVL Tree, etc.

There is no need to sort the set assets in C++ that are implemented using self-balancing binary search trees, which is why each operation, such as insertion, searching, deletion, etc., takes O(log n) time.

Now, simply copy the items of the set one by one from the beginning to the tree while doing an in-order traversal of the tree. Care should be taken when copying each item of a set from its beginning, and we first copy it to the tree while doing inorder traversal, then remove it from the set as well.

Time Complexity: O(nlogn) and Auxiliary Space: O(n)
*/
#include <iostream>
#include <set>
#include <queue>
using namespace std;

// Definition of a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform in-order traversal and store values in a set
void storeInorder(Node* root, set<int>& nodes) {
    if (!root) return;
    storeInorder(root->left, nodes);
    nodes.insert(root->data);
    storeInorder(root->right, nodes);
}

// Function to convert tree to BST using in-order traversal
void convertToBST(Node* root, set<int>& nodes, set<int>::iterator& it) {
    if (!root) return;
    convertToBST(root->left, nodes, it);
    root->data = *it;
    ++it;
    convertToBST(root->right, nodes, it);
}

// Function to create a binary tree from user input
Node* createTree(int n) {
    if (n <= 0) return nullptr;
    
    cout << "Enter root value: ";
    int val;
    cin >> val;
    Node* root = new Node(val);
    
    queue<Node*> q;
    q.push(root);
    int count = 1;
    
    while (!q.empty() && count < n) {
        Node* curr = q.front();
        q.pop();
        
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->left = new Node(val);
            q.push(curr->left);
            count++;
        }
        if (count >= n) break;
        
        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->right = new Node(val);
            q.push(curr->right);
            count++;
        }
    }
    return root;
}

// Function to print in-order traversal of the tree
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    Node* root = createTree(n);
    
    cout << "Original Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;
    
    // Store the values of the binary tree in a set (which will be in sorted order)
    set<int> nodes;
    storeInorder(root, nodes);
    
    // Convert the binary tree to BST by replacing node values using an in-order traversal
    auto it = nodes.begin();
    convertToBST(root, nodes, it);
    
    cout << "Converted BST Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;
    
    return 0;
}
