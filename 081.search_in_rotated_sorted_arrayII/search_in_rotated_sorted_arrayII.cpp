class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			int len = nums.size();
			int left = 0;
			int right = len;
			while(left < right)
			{
				int mid = (left + right) / 2;
				if(nums[mid] == target)
				{
					return true;
				}
				if(nums[left] < nums[mid])
				{
					if(target < nums[mid] && target >= nums[left])
					{
						right = mid;
					}
					else
					{
						left = mid + 1;
					}
				}
				else if(nums[mid] < nums[left])
				{
					if(target > nums[mid] && target <= nums[right - 1])
					{
						left = mid + 1;
					}
					else
					{
						right = mid;
					}
				}
				else
					left++;
			}
			return false;
		}
};
