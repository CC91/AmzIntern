// 230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        dfs(root, k, res);
        return res;
    }
    
    void dfs(TreeNode* &root, int &k, int &res) {
        if (!root ||k==0) return;
        dfs(root->left, k, res);
        if (--k==0) {
            res = root->val;
            return;
        }
        dfs(root->right, k, res);
    }
};


class Solution {
public: // iteration
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (p) {
            stk.push(p);
            p = p->left;
        }
        
        while (k && (p||!stk.empty())) {
            if (!p) {
                p = stk.top();
                stk.pop();
                --k;
                if (k==0) return p->val;
                p = p->right;
            }
            else {
                stk.push(p);
                p = p->left;
            }
        }
        return p->val;
    }
};