#include <iostream>
#include <algorithm>

using namespace std;

/*

The function is called isBalanced() and it takes a pointer to the root node of the binary tree as input. The function first checks if the root node is null. If it is, then the tree is trivially balanced, so the function returns true. Otherwise, the function calls the Height() function to recursively calculate the height of the left and right subtrees of the root node.

The Height() function takes a pointer to a node as input and returns the height of the subtree rooted at that node. The height of a node is defined as the number of edges from the node to the furthest leaf node.

If the height of the left and right subtrees of the root node are both equal to 0, then the root node is a leaf node and the tree is balanced. Otherwise, if the height of the left and right subtrees are equal, then the tree is balanced. Otherwise, if the height of the left and right subtrees differ by more than 1, then the tree is not balanced and the function returns false.

Finally, if the function reaches this point, then the tree is balanced and the function returns true.

*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)  return true;
		if (Height(root) == -1)  return false;
		return true;
    }
    int Height(TreeNode* root) {
		if (root == NULL)  return 0;
		int leftHeight = Height(root->left);
		int rightHight = Height(root->right);
		if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;
		return max(leftHeight, rightHight) + 1;
    }
};