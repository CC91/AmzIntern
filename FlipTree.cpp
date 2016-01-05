// Flip Tree

vector<TreeNode*> flip(TreeNode* root) {
	vector<TreeNode*> res;
	helper(root, res);
}

void helper(TreeNode* root, vector<TreeNode*> &res) {
	if (!root->left && !root->right) {
		res.push_back(root);
		return;
	}

	if (root->left) {
		root->left->left = root;
		root->left = NULL;
	}

	if (root->right) {
		root->right->right = root;
		root->right = NULL;
	}
}