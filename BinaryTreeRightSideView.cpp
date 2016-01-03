// 199. Binary Tree Right Side View

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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> curL, nextL;
        curL.push(root);
        int num;
        while (1) {
            while (!curL.empty()) {
                TreeNode* curNode = curL.front();
                curL.pop();
                num = curNode->val;
                if (curNode->left) nextL.push(curNode->left);
                if (curNode->right) nextL.push(curNode->right);
            }
            res.push_back(num);
            swap(curL, nextL);
            if (curL.empty()) return res;
        }
    }
};