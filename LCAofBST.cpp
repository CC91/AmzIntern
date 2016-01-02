// 235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: // recursion
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root ||root==p ||root==q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        return !l?r:!r?l:root;
    }
};

// sol2: find p q positions
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root ||root==p ||root==q) return root;
        int match = countMatch(root->left, p, q);
        if (match==1) return root;
        else if (match==2) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
    
    int countMatch(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int match = countMatch(root->left, p, q)+countMatch(root->right, p, q);
        if (root==p ||root==q) return match+1;
        else return match;
    }
    
};