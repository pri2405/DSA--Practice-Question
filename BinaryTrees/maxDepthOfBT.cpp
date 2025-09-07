// Leetcode q no. - 104

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// 1st Approach 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){ 
            return 0;
        }
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return max(left,right);
    }
};