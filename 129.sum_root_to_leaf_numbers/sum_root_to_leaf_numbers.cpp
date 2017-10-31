class Solution
{
	public:
		int sumNumbers(TreeNode *root)
		{
			return sumNumbers(root, 0);
		}
		int sumNumbers(TreeNode *root, int result)
		{
			if(root == NULL)
				return 0;
			if(root->left == NULL && root->right == NULL)
			{
				return result * 10 + root->val;
			}
			return sumNumbers(root->left, result * 10 + root->val) + 
				sumNumbers(root->right, result * 10 + root->val);
		}
};

