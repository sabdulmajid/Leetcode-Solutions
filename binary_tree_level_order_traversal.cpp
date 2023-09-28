#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

This code defines a TreeNode structure to represent a binary tree and a Solution class with a method levelOrder, which returns a vector of vectors representing the level-order traversal of a given binary tree. The levelOrder method initializes an empty result vector and a queue for BFS traversal, starting with the root node. It then enters a loop, processing each level of the tree, dequeuing nodes from the current level, and enqueuing their children for the next level. Each level's node values are collected into a temporary vector, which is then added to the result vector.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};