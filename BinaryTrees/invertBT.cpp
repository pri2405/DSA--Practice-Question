// Leetcode q no. - 226 (Invert Binary Tree)

// Given the root of a binary tree, invert the tree, and return its root.

// 1st Approach - Depth First Search
// T.C. - O(n)  & S.C. - O(h)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

// 2nd Approach - Breadth First Search
// T.C. - O(n)  &  S.C. - O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); 

            TreeNode* temp = node->left; 
            node->left = node->right;
            node->right = temp;

            q.pop(); 

            if (node->left != NULL) q.push(node->left); 
            if (node->right != NULL) q.push(node->right);
        }
        return root;
    }
};