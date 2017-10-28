class Solution
{
	public:
		int minDepth(TreeNode *root)
		{
			if(root == NULL)
				return 0;
			if(!root->left)
			{
				return 1 + minDepth(root->left);
			}
			if(!root->right)
			{
				return 1 + minDepth(root->right);
			}
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}
};

