class Solution
{
	public:
		int maxSubArray(vector<int>& nums)
		{
			int temp = 0, result = nums[0];
			for(int i = 0; i < nums.size(); i++)
			{
				temp = max(temp + nums[i], nums[i]);
				result = max(result, temp);
			}
			return result;
		}
};

