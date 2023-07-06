#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*

A binary tree is a data structure that consists of nodes arranged in a tree-like structure. Each node in the tree has zero or more child nodes. The child nodes are arranged in a left-to-right order.

The function inverts the tree by recursively swapping the left and right child nodes of each node. The function starts at the root node and then recursively calls itself on the left and right child nodes. The function stops when it reaches a leaf node, which is a node that has no child nodes.

*/


// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // to invert the tree, you need to look at the left and right nodes of the root node, then swap them. We will definitely need to use recursion here. Some thing along the lines of:
        if (root == nullptr)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;

        return root;
    }
};
