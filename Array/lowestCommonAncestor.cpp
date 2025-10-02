// Leetcode q no. - 236 (Lowest Common Ancestor)

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// 1st Approach - Path Method
// T.C. - O(N) & S.C. - O(N)     ---- where N represent no. of nodes in Binary Tree
class Solution {
public:
    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool &found) {
        if(!root || found) return;

        path.push_back(root);

        if(root == target) {
            found = true;
            return;
        }

        findPath(root->left, target, path, found);
        findPath(root->right, target, path, found);

        if(!found) path.pop_back();      // backtracking if not present in the branch
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        bool find1 = false;
        bool find2 = false;

        findPath(root, p, path1, find1);
        findPath(root, q, path2, find2);

        TreeNode* lca = NULL;
        for(int i=0; i<min(path1.size(), path2.size()); i++) {
            if(path1[i] == path2[i]) lca = path1[i];
            else break;
        }
        return lca;
    }
};

// 2nd Approach - recursive DFS
class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL)  return false;
        if(root==target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncestor(root->left, p, q);
        else if(exists(root->right, p) && exists(root->right, q)) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

// 3rd Approach - optimized recursive DFS
// T.C. - O(N) & S.C. - O(H)  --- where N - no. of Nodes in Tree & H - height of tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};