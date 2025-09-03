// Leetcode q no. - 94  (Binary Tree Inorder Traversal)

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// 1st Approach  -  recursive approach
class Solution {
public:
    void helper(TreeNode* root, vector<int> &ans) {    // T.C. - O(n) & S.C. - O(n)
        if(!root) return;

        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// 2nd Approach  -  using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {      // T.C. - O(n) & S.C. - O(n)
        vector<int> res;
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;   
    }
};

// 3rd Approach  -  Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {      // T.C. - O(n) & S.C. - O(1)
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr) pred = pred->right;
                if(pred->right==NULL){  // link to curr
                    pred->right = curr;
                    curr = curr->left;
                }
                else{                 // unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{   // curr->left == NULL
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};