class Solution
{
	public:
		vector<vector<int> > levelOrder(TreeNode *root)
		{
			queue<TreeNode *> next_level, cur_level;
			vector<vector<int> > res;
			if(root == NULL)	return res;
			cur_level.push(root);
			while(!cur_level.empty())
			{
				vector<int> level;
				while(!cur_level.empty())
				{
					TreeNode *p = cur_level.front();
					cur_level.pop();
					level.push_back(p);
					if(p->left != NULL) next_level.push(p->left);
					if(p->right != NULL) next_level.push(p->right);
				}
				res.push_back(level);
				swap(next_level, cur_level);
			}
			return res;
		}
};


