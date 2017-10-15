class Solution
{
	public:
		vector<int> inorderTraversal(TreeNode *root)
		{
			vector<int> res;
			stack<const TreeNode *> s;
			TreeNode *p = root;
			while(p != NULL || !s.empty())
			{
				while(p != NULL)
				{
					s.push(p->val);
					p = p->left;
				}
				if(!s.empty())
				{
					p = s.top();
					res.push(p->val);
					s.pop();
					p = p->right;
				}
			}
			return res;
		}
};
