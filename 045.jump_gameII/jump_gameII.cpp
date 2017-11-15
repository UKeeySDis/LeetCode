class Solution
{
	public:
		int jump(vector<int>& nums)
		{
			int res = 0, last = 0, cur = 0;
			for(int i = 0; i < nums.size(); i++)
			{
				if(last < i)
				{
					last = cur;
					++res;
				}
				cur = max(cur, i + nums[i]);
			}
			return res;
		}
};

