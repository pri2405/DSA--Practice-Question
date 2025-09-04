// Leetcode q no. - 101

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// 1st Approach  -  recursive approach
// T.C. - O(n)  no. of nodes in tree
// S.C. - O(h)  height of tree
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r){  
        if(l==NULL && r==NULL)  return true;
        if(l == NULL || r == NULL)  return false;
        bool a = check(l->left, r->right);
        bool b = check(l->right, r->left);
        return (l->val==r->val && a && b);
    }
    bool isSymmetric(TreeNode* root){
        if(root==NULL) return true;
        return check(root->left, root->right);
    }
};