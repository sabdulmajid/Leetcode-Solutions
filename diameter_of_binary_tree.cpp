#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Code Explanation

This code defines a class Solution that contains a method diameterOfBinaryTree that takes a pointer to a TreeNode object and returns an integer. The method calculates the diameter of the binary tree rooted at the given node. The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree. The method uses a recursive depth-first search (DFS) algorithm to calculate the depths of the left and right subtrees, and then returns the maximum diameter (which may not pass through the root). The class also contains a private class variable diam that stores the maximum diameter found so far, and a private recursive DFS method that calculates the depth of each subtree.

*/

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
    int diameterOfBinaryTree(TreeNode* root) {
        // Check if tree exists
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = DFS(root->left);
        int rightDepth = DFS(root->right);
        
        // Return largest diameter (maybe not through root)
        return max(diam, leftDepth + rightDepth);
    }
    
// Good practice to make internal methods and class variables private
private:
    
    // Class variable to save max diameter found
    int diam = 0;
    
    // Recursive DFS method
    int DFS(TreeNode* root) {
        // Check for leaf node
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = DFS(root->left);
        int rightDepth = DFS(root->right);
        
        // Diameter is the number of edges between the farthest nodes
        diam = max(diam, leftDepth + rightDepth);
        
        // Return the depth of the current subtree
        return max(leftDepth, rightDepth) + 1;
    }
};