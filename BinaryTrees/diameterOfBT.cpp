// Leetcode q no. - 543 (Diameter of a Binary tree)


// 1st approach - using depth first search
class Solution {
public:
    int dfs(TreeNode* root, int &ans){
        if(!root) return 0;

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        ans = max(ans, left+right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};