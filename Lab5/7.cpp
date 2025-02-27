/*Given the root of a binary tree, invert the tree such that the left and right subtrees are swapped.

Each node in the tree has a unique integer value. Write a CPP program to invert the binary tree.

INPUT FORMAT :
The input consists of two lines:
1. The first line contains an integer n, representing the number of nodes in the tree.
2. The second line contains n integers, representing the level-order traversal of the tree.  -1 has been used to denote NULL nodes (i.e., positions where the tree does not have a node).

Example Input :
7
4 2 7 1 3 6 9

        4
       / \
      2   7
     / \  / \
    1  3 6  9

OUTPUT FORMAT:
The output consists of two lines:
1. The first line contains the pre-order traversal of the tree before inverting it.
2. The second line contains the pre-order traversal of the tree after inverting it.

Example Output :
4 2 1 3 7 6 9
4 7 9 6 2 3 1

        4
       / \
      7   2
    / \   / \
    9  6 3  1
    */
#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *createNode(int value)
{
    if (value == -1)
        return nullptr;
    return new TreeNode(value);
}

TreeNode *insertLevelOrder(vector<int> &arr, TreeNode *root, int i, int n)
{
    if (i < n && arr[i] != -1)
    {
        root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return nullptr;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void printPreorder(TreeNode *node)
{
    if (!node)
        return;
    cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    TreeNode *root = nullptr;
    root = insertLevelOrder(arr, root, 0, n);

    printPreorder(root);
    cout << endl;

    root = invertTree(root);
    printPreorder(root);
    cout << endl;

    delete root;

    return 0;
}