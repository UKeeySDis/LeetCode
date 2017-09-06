/* 和3sum类似的题,明白了3sum的做法之后,做这道题就比较简单了,维持一个min_close就行 */
class Solution
{
	public:
		int threeNumCloseset(vector<int>& nums, int target)
		{
			int min_close = 100000;
			int len = nums.size() - 2;
			int res;
			sort(nums.begin(), nums.end());
			for(int i = 0; i < len; i++)
			{
				if(i != 0 && nums[i] == nums[i - 1])
					continue;
				int left = i + 1;
				int right = nums.size() - 1;
				while(left < right)
				{
					int sum = nums[i] + nums[left] + nums[right];
					int abs_close = abs(sum - target);
					if(sum == target)
					{
						return target;
					}
					else if(sum < target)
					{
						left++;
					}
					else
					{
						right--;
					}
					if(abs_close < min_close)
					{
						min_close = abs_close;
						res = sum - target;
					}
				}
			}
			return res + target;
		}
};

