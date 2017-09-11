/* 相当于是二分查找的变种
 * 需要来确定是左/右区间哪个是有序的
 * 然后再判断要查找的元素是否在有序区间内
 * 否则去另外一个区间
 * 重复以上过程
 */
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size();
			while(left < right)
			{
				int mid = left + (right - left) / 2;
				if(nums[mid] == target)
					return mid;
				if(nums[left] < nums[mid])
				{
					if(nums[left] <= target && nums[mid] > target)
						right = mid;
					else
						left = mid + 1;
				}
				else 
				{
					if(nums[mid] < target && nums[right - 1] >= target)
						left = mid + 1;
					else
						right = mid;
				}
			}
			return -1;
		}
};
