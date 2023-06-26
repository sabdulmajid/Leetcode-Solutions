#include <iostream>
#include <vector>

using namespace std;

/*

The function first checks if the root node is null. If it is, then the LCA is null, because there is no ancestor of two nodes that do not exist. 
Otherwise, the function checks if the root node's value is greater than both of the nodes' values. If it is, then the LCA must be in the left subtree of the root node, so the function recursively calls itself on the left subtree. 
Similarly, if the root node's value is less than both of the nodes' values, then the LCA must be in the right subtree of the root node, so the function recursively calls itself on the right subtree. Otherwise, the root node must be the LCA, so the function returns the root node.

*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root==nullptr) return nullptr;
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};