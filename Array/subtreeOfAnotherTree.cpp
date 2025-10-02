// Leetcode q no. - 572 (Subtree of Another tree)

// Given the roots of two binary trees root and subRoot, 
// return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// 1st Approach -  Recursive DFS with Tree Matching
// T.C. - O(n1 * n2) ---- where n1 - nodes in root & n2 - nodes in subRoot
// S.C. - O(h)  --- where h - height of tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val){
            return isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// 2nd Approach - Serialization
// T.C. - O(n1 + n2) --- where n1 - nodes in root & n2 - nodes in root
class Solution {
public:
    string serialize(TreeNode* node) {
        if (!node) return "N";
        return "(" + to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right) + ")";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerialized = serialize(root);
        string subRootSerialized = serialize(subRoot);
        cout<<rootSerialized<<" "<<subRootSerialized;
        return rootSerialized.find(subRootSerialized) != string::npos;
    }
};