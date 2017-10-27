class Solution
{
	public:
		bool isValidBST(TreeNode *root)
		{
			return isValidBST(root, NULL, NULL);
		}
		bool isValidBST(TreeNode *root, TreeNode *min_node, TreeNode *max_node)
		{
			if(root == NULL)
				return true;
			if(min_node && root->val <= min_node->val || max_node && root->val >= max_node->val)
				return false;
			return isValidBST(root->left, min_node, root) && isValidBST(root->right, root, max_node);
		}
};

class Solution
{
	public:
		bool isValidBST(TreeNode *root)
		{
			return isValidBST(root, NULL);
		}
		bool isValidBST(TreeNode *root, TreeNode* &prev)
		{
			if(root == NULL)	return true;
			if(!isValidBST(root->left, prev))	return false;
			if(prev != NULL && prev->val >= root->val)	return false;
			return isValidBST(root->right, prev);
		}
};
