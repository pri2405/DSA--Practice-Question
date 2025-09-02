// Leetcode q no. - 145 (Binary Tree Postorder Traversal)

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// 1st Approach - using recursion
class Solution {                              // T.C. - O(n)  &  S.C. - O(n)
public:
    void postOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

// 2nd Approach - using stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {           // T.C. - O(n)  &  S.C. - O(n)
        if (!root) return {};

        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            result.push_back(current->val);

            if (current->left) {
                st.push(current->left);
            }
            if (current->right) {
                st.push(current->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// 3rd Approach - using two stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {            // T.C. - O(n) & S.C. - O(n)
        if (!root) return {};

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->left) {
                st1.push(current->left);
            }
            if (current->right) {
                st1.push(current->right);
            }
        }

        vector<int> result;
        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};