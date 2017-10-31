class Solution
{
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum)
		{
			vector<vector<int> > res;
			vector<int> cur;
			pathSum(root, sum, res, cur);
			return res;
		}
		void pathSum(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &cur)
		{
			if(root == NULL)
				return ;
			cur.push_back(root->val);
			if(root->val == sum && root->left == NULL && root->right == NULL)
			{
				res.push_back(cur);
			}
			pathSum(root->left, sum - root->val, res, cur);
			pathSum(root->right, sum - root->val, res, cur);
			cur.pop_back();
		}
};

