class Solution
{
	public:
		vector<vector<int> > subsets(vector<int>& nums)
		{
			sort(nums.begin(), nums.end());
			vector<vector<int> > res;
			vector<int> cur;
			subsets(nums, cur, 0, res);
			return res;
		}
		void subsets(const vector<int> &nums, vector<int> &cur, int size, vector<vector<int> > &res)
		{
			if(size == nums.size())
			{
				res.push_back(cur);
				return;
			}
			subsets(nums, cur, size + 1, res);

			cur.push_back(nums[size]);
			subsets(nums, cur, step + 1, res);

			cur.pop_back();
		}
};
