class Solution
{
	public:
		vector<vector<int> > combine(int n, int k)
		{
			vector<vector<int> > res;
			vector<int> cur;
			combine(res, cur, 0, n, k, 1);
			return res;
		}
		void combine(vector<vector<int> > &res, vector<int> &cur, int step, int n, int k, int n_th)
		{
			if(step == k)
			{
				res.push(cur);
				return ;
			}
			for(int i = n_th; i <= n;)
			{
				cur.push_back(i);
				//为了避免重复,所以需要再进入到下一层递归前进行i++操作
				i++;
				combine(res, cur, step + 1, n, k, i);
				cur.pop_back();
			}
		}
};

