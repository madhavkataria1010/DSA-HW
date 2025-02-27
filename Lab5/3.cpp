/*Given a Binary Search Tree (BST), modify it such that:
1. All odd-valued nodes are removed from the BST.
2. The BST property is maintained after removal.

Return the root of the modified BST. The input will be an integer n, denoting the number of nodes in the BST. This is followed by a line containing n integers, denoting the value of nodes in the order of their insertion. You only need to implement the removeOddsFromBST function. DO NOT modify any existing functions.

Example 1:
Input:
       10
      /  \
     5    15
    / \   / \
   2  7 12  18

Output:
       10
      /  \
     2    12
            \
            18

Explanation:
Odd-valued nodes (5, 7, 15) are removed.
The BST is reconstructed while maintaining its properties.

Example 2
Input:

       8
      / \
     4   12
    / \   / \
   2   6 10 14

Output:

       8
      / \
     4   12
    / \   / \
   2   6 10 14

Explanation:
No changes since all nodes are even.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *mergeTrees(TreeNode *left, TreeNode *right)
{
    if (!left)
        return right;
    TreeNode *cur = left;
    while (cur->right)
        cur = cur->right;
    cur->right = right;
    return left;
}

TreeNode *removeOddsFromBST(TreeNode *root)
{
    if (!root)
        return root;
    root->left = removeOddsFromBST(root->left);
    root->right = removeOddsFromBST(root->right);

    if (root->val % 2 != 0)
    {
        TreeNode *merged = mergeTrees(root->left, root->right);
        delete root;
        return merged;
    }
    return root;
}

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    root = removeOddsFromBST(root);

    inorder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    return 0;
}
