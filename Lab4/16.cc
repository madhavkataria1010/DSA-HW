/*Write a program to find the lowest common ancestor (LCA) of two given nodes in a Binary Search Tree (BST). The lowest common ancestor is defined between two nodes p and q as the lowest node in the BST that has both p and q as descendants (where we allow a node to be a descendant of itself).

Input format:
           The first line contains an integer n, the number of nodes in the BST.
           The next n lines each contain an integer val, representing the value of each node to be inserted into the BST.
           The next two lines each contain an integer, p and q, representing the values of the two nodes for which the LCA is to be found.

Output format:
            A single line containing the value of the lowest common ancestor (LCA) node.
            If find none, Print “NONE”.*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insertBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

bool exists(TreeNode *root, int val)
{
    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    else if (val < root->val)
        return exists(root->left, val);
    else
        return exists(root->right, val);
}

TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
{
    int a = (p < q) ? p : q;
    int b = (p < q) ? q : p;

    while (root != NULL)
    {
        if (root->val > b)
            root = root->left;
        else if (root->val < a)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main()
{
    int n, p, q;
    cin >> n;

    TreeNode *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        root = insertBST(root, val);
    }

    cin >> p >> q;

    if (!exists(root, p) || !exists(root, q))
    {
        cout << "NONE" << endl;
        return 0;
    }

    TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
    {
        cout << lca->val << endl;
    }
    else
    {
        cout << "NONE" << endl;
    }

    return 0;
}