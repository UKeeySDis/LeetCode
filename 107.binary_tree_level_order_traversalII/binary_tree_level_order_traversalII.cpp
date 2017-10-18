/* 层次遍历的变种
 * 将最后得到的结果调用reverse函数翻转一次就行了
 */
class Solution
{
	public:
		vector<vector<int> > levelOrderBottom(TreeNode *root)
		{
			vector<vector<int> > result;
			queue<TreeNode *> cur, next;
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
					if(p->left != NULL)	next.push(p->left);
					if(p->right != NULL) next.push(p->right);
				}
				swap(cur, next);
				result.push_back(level);
			}
			reverse(result.begin(), result.end());
			return result;
		}
};


