//Leetcode q no. - 102 (Binary Tree Level Order Traversal)

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// 1st approach - uing queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            int n = q.size();
            vector<int> v(n);
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();

                v[i] = temp->val;
                if(temp->left!=NULL)  q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            ans.push_back(v);
        }

        return ans;
    }
};