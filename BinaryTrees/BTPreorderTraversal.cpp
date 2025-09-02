// Leetcode q no. - 144 (Binary Tree Preorder Traversal)

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// 1st Approach - recursive approach
class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &ans) {        // T.C. - O(n) & S.C. - O(n)
        if(!root) return;

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};

// 2nd Approach - using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {       // T.C. - O(n) & S.C. - O(n)
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);

            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }

        return ans;
    }
};