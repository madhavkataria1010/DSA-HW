/*Given a Binary Search Tree (BST) with Two nodes swapped, the task is to recover the original BST.

Input:

	  10
	//	\\
	5	 8
       // \\
    2   20

Output:

		    10
	       //         \\
	    5            20
	  //  \\
         2    8

Explanation: The nodes 20 and 8 were swapped.


Input:

	      5
	     //	\\
          10  20
         // \\
        2   8

Output:

		10
	       //  \\
	    5     20
	   // \\
         2    8

Explanation: The nodes 10 and 5 were swapped.


Using One Traversal – O(n) Time and O(h) Space

Since the Inorder traversal of BST is always a sorted array, the problem can be reduced to a problem where two elements of a sorted array are swapped. We do an in-order traversal of the tree, and whenever we find nodes that are out of sorted order, we store those nodes.

Two cases arise:

The two are not adjacent. In this case, we find two violations.
The two swapped nodes are adjacent in Inorder. We find only one violation in this case.


We maintain three-pointers, first, middle, and last. When the first point where the current node value is smaller than the previous node value is found, update the first with the previous node & the middle with the current node. 
When we find the second point where the current node value is smaller than the previous node value, we update the last with the current node.
If the last node value is null, then two swapped nodes of BST are adjacent, i.e. first and middle; otherwise, first and last.*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* first = nullptr;
Node* middle = nullptr;
Node* last = nullptr;
Node* prevNode = nullptr;

void correctBSTUtil(Node* root) {
    if (!root) return;
    
    correctBSTUtil(root->left);
    
    if (prevNode && root->data < prevNode->data) {
        if (!first) {
            first = prevNode;
            middle = root;
        }
        else {
            last = root;
        }
    }
    
    prevNode = root;
    
    correctBSTUtil(root->right);
}

void correctBST(Node *root) {
    first = middle = last = prevNode = nullptr;
    
    correctBSTUtil(root);
    
    if (first && last)
        cout << "Swapped nodes: " << first->data << " and " << last->data << endl;
    else if (first && middle)
        cout << "Swapped nodes: " << first->data << " and " << middle->data << endl;
    
    if (first && last)
        swap(first->data, last->data);
    else if (first && middle)
        swap(first->data, middle->data);
}

void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

Node* buildTree(int numNodes) {
    if (numNodes <= 0) return nullptr;
    
    int val;
    cout << "Enter root value: ";
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    int count = 1;
    
    while (count < numNodes && !q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->left = new Node(val);
            q.push(curr->left);
            count++;
            if (count >= numNodes) break;
        }
        
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

int main() {
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    
    Node* root = buildTree(numNodes);
    cout << "Original Tree (Level Order): ";
    printLevelOrder(root);
    cout << endl;

    correctBST(root);
    
    cout << "Corrected BST (Level Order): ";
    printLevelOrder(root);
    cout << endl;
    
    return 0;
}