class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			unordered_map<int, bool> used;
			int len = nums.size();
			for(int i = 0; i < len; i++)
			{
				used[nums[i]] = false;
			}
			int longest = 0;
			for(int i = 0; i < len; i++)
			{
				if(used[nums[i]] == true)
					continue;
				int length = 1;
				used[nums[i]] = true;
				for(int j = nums[i] + 1; used.find(j) != used.end(); j++)
				{
					used[j] = true;
					++length;
				}
				for(int j = nums[i] - 1; used.find(j) != used.end(); j--)
				{
					used[j] = true;
					++length;
				}
				longest = max(longest, length);

			}
			return longest;
		}
};
