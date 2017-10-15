class Solution
{
	public:
		vector<int> preorderTraversal(TreeNode *root)
		{
			stack<const TreeNode *> s;
			vector<int> res;
			if(root == NULL)	return NULL;
			s.push(root);
			while(!s.empty())
			{
				const TreeNode *p = s.top();
				s.pop();
				res.push_back(p->val);
				if(p->right != NULL)	s.push(p->right);
				if(p->left != NULL)		s.push(p->left);
			}
			return res;
		}
};
