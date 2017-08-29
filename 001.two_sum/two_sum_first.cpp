class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			vector<int>::iterator first = nums.begin();
			vector<int>::iterator end = nums.end();
			for(;first != end; first++)
			{
				int x = target - *first;
				vector<int>::iterator res = find(first + 1, end, x);
				if(res != end)
				{
					result.push_back(first - nums.begin());
					result.push_back(res -  nums.begin());
					return result;
				}
			}
		}
};
