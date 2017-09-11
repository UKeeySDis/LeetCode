/* 和remove_duplicates_from_sorted_array思路一想
 * 这里只用改下index就行了
 */
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int len = nums.size();
			if(len <= 2)    return len;
			int index = 2;
			for(int i = index; i < len; i++)
			{
				if(nums[i] != nums[index - 2])
					nums[index++] = nums[i];
			}
			return index;
		}
};
