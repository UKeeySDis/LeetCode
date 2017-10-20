class Solution
{
	public:
		void flatten(TreeNode *root)
		{
			if(root == NULL)	return;

			stack<TreeNode *> s;
			s.push(root);

			while(!s.empty())
			{
				TreeNode *p = s.top();
				s.pop();

				if(p->right)
				{
					s.push(p->right);
				}
				if(p->left)
				{
					s.push(p->left);
				}
				p->left= NULL;
				if(!s.empty())
					p->right = s.top();
			}
		}
};


