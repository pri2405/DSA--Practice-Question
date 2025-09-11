// Leetcode q no. - 1448 (Count Good Nodes in a Binary Tree) 

// Given a binary tree root, a node X in the tree is named good 
// if in the path from root to X there are no nodes with a value greater than X.
// Return the number of good nodes in the binary tree.

// 1st Approach - DFS
// T.C. - O(n) & S.C. - O(h)      ----->   n - no. of nodes & h - height of BT
class Solution {
public:
    void solve(TreeNode * node,int cpm, int &ans){
        if(!node) return;
        if(node->val >= cpm) {
            ans++;
            cpm = node->val;
        }
        solve(node->left,cpm,ans);
        solve(node->right,cpm,ans);
    }
    int goodNodes(TreeNode* root) {
        int value = root->val;
        int ans = 0;
        solve(root, value, ans);
        return ans;
    }
};