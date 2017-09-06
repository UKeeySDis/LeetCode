/* 开始的想法是用深搜,O(n^3)的复杂度,果然超时了。后面想了一下,没有想到什么好的方法。
 * 于是看了题解,O(n^2)的复杂度,开两个指针,往中间扫
 * 先将元素排序,外层for只用遍历0-size-2,并且将相等的元素跳过,如果大于0就证明后面的元素全部大于0了,不可能和为0,直接break
 * 内层for遍历剩下的元素,两两相加,如果等于-nums[i],则为解,记录下来并且将相等的元素跳过(防止有重复的解)
 * 如果大于-nums[i],证明当前的和过大,需要减小一点,则将last_pos左移
 * 如果小于-nums[i],证明过小,需要增大,将start_pos右移,
 */ 
class Solution {
	public:
		vector<vector<int> > threeSum(vector<int>& nums) {
			vector<vector<int> >res;
			int len = nums.size() - 2;
			sort(nums.begin(), nums.end());
			for(int i = 0; i < len; i++)
			{
				if(nums[i] > 0)
					break;
				if(i != 0 && nums[i] == nums[i - 1])
					continue;
				int start_pos = i + 1;
				int last_pos = nums.size() - 1;
				int target = -nums[i];
				while(start_pos < last_pos)
				{
					int two_sum = nums[start_pos] + nums[last_pos];
					if(two_sum == target)
					{
						vector<int>one_ans;
						one_ans.push_back(nums[i]);
						one_ans.push_back(nums[start_pos]);
						one_ans.push_back(nums[last_pos]);
						res.push_back(one_ans);
						start_pos++;
						last_pos--;
						while(start_pos < last_pos && nums[start_pos] == nums[start_pos - 1])
						{
							start_pos++;
						}
						while(start_pos < last_pos && nums[last_pos] == nums[last_pos + 1])
						{
							last_pos--;
						}
					}
					else if(two_sum > target)
					{
						last_pos--;
					}
					else
					{
						start_pos++;
					}
				}
			}
			return res;


		}
};

