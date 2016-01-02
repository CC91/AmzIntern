// 98. Validate Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // sol1: top-down recursion
class Solution {
public: 
    bool isValidBST(TreeNode* root) {
        return validHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool validHelper(TreeNode* root, long MIN, long MAX) {
        if (!root) return true;
        return root->val>MIN && root->val<MAX && validHelper(root->left, MIN, root->val) && validHelper(root->right, root->val, MAX);
    }
};

// sol2: inorder-traversal recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validHelper(root, prev);
    }
    
    bool validHelper(TreeNode* node, TreeNode* &prev) {
        if (!node) return true;
        if (!validHelper(node->left, prev)) return false;
        if (prev!=NULL && prev->val>=node->val) return false;
        prev = node;
        return validHelper(node->right, prev);
    }
};