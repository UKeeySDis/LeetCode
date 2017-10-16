class Solution
{
	public:
		vector<int> postorderTraversal(TreeNode *root)
		{
			vector<int> result;
			stack<const TreeNode *> s;
			const TreeNode *p = root, *pre = NULL;

			while(p != NULL || !s.empty())
			{
				while(p != NULL)
				{
					s.push(p);
					p = p->left;
				}
				p = s.top();
				if(p->right == NULL || p->right == pre)
				{
					result.push_back(p->val);
					s.pop();
					pre = p;
					p = NULL;
				}
				else
				{
					p = p->right;
				}
			}
			return result;
		}
};

