/*You are given a binary tree having 'n' nodes. Each node of the tree has an integer value.
Your task is to find the maximum possible sum of a simple path between any two nodes (possibly the same) of the given tree.
A simple path is a path between any two nodes of a tree, such that no edge in the path is repeated twice. The sum of a simple path is defined as the summation of all node values in a path.

Example:

Sample Input 1:
1 2 3 4 -1 -1 -1 -1 -1
Sample Output 1:
10
Explanation For Sample Input 1:
The tree looks as follows:
                        1
                       / \
                      2   3
                     /
                    4
The path between Node 3 (with value 3) and Node 4 (with value 4) produces the maximum sum, i.e., 10. Hence, the maximum possible sum is 10 in this case.

Sample Input 2:
2 4 -1 3 6 -1 -1 -1 -1
Sample Output 2:
13
Explanation For Sample Input 2:
The tree looks as follows:
                        2
                       /
                      4
                     / \
                    3   6
The path between Node 3 (with value 3) and Node 4 (with value 6) produces the maximum sum, i.e., 13. Hence, the maximum possible sum is 13 in this case.

Expected time complexity:
 The expected time complexity is O(n).
Constraints:
1 <= 'n' <= 10^6
-10^5 <= 'data' <= 10^5 and 'data' !=-1*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    size_t i = 1;

    while (i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size())
        {
            int leftChild = nodes[i++];
            if (leftChild != -1)
            {
                curr->left = new TreeNode(leftChild);
                q.push(curr->left);
            }
        }

        // Right child
        if (i < nodes.size())
        {
            int rightChild = nodes[i++];
            if (rightChild != -1)
            {
                curr->right = new TreeNode(rightChild);
                q.push(curr->right);
            }
        }
    }
    return root;
}

int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;

    function<int(TreeNode *)> helper = [&](TreeNode *node) -> int
    {
        if (!node)
            return 0;

        int leftGain = max(helper(node->left), 0);
        int rightGain = max(helper(node->right), 0);

        res = max(res, node->val + leftGain + rightGain);

        return node->val + max(leftGain, rightGain);
    };

    helper(root);
    return res;
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nodes;
    int num;

    while (ss >> num)
    {
        nodes.push_back(num);
    }

    TreeNode *root = buildTree(nodes);
    cout << maxPathSum(root) << endl;
    return 0;
}
