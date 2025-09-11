// Leetcode q no. - 112 (Path Sum)

// Given the root of a binary tree and an integer targetSum, 
// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

// 1st Approach - recursive approach
// T.C. - O(n) & S.C. - O(h)      ----- n - no. of nodes & h - height of BT
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;

        int newSum = targetSum - root->val;
        if(root->left == NULL && root->right == NULL) return (newSum == 0);

        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};

// 2nd Approach - Iterative Approach
// T.C. - O(n) & S.C. - O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});

        while (!s.empty()) {
            TreeNode* node = s.top().first;
            int sum = s.top().second;
            s.pop();

            if (!node->left && !node->right && sum == targetSum) return true;

            if (node->right) {
                s.push({node->right, sum + node->right->val});
            }
            if (node->left) {
                s.push({node->left, sum + node->left->val});
            }
        }

        return false;
    }
};