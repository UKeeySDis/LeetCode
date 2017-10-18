/* 层次遍历的变种
 * 用一个rever_flag变量来判断当前层是否需要翻转即可
 */
class Solution
{
	public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root)
		{
			vector<vector<int> > result;
			queue<TreeNode *> cur, next;
			bool rever_flag = true;
			if(root == NULL)	return result;
			cur.push(root);
			while(!cur.empty())
			{
				vector<int> level;
				while(!cur.empty())
				{
					TreeNode *p = cur.front();
					cur.pop();
					level.push_back(p->val);
					if(p->left != NULL) next.push(p->left);
					if(p->right != NULL) next.push(p->right);
				}
				swap(cur, next);
				if(rever_flag)
				{
					result.push_back(level);
					rever_flag = false;
				}
				else
				{
					reverse(level.begin(), level.end());
					result.push_back(level);
					rever_flag = true;
				}
			}
			return result;
		}
};
