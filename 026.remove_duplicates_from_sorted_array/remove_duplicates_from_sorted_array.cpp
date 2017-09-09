/* 这道题刚开始并没有注意到nums还需要修改才行
 * 于是填了点代码,结果慢到不行
 * 后面看了0ms的提交,感觉智商压制....
 * 其实也很有道理,就是当前后不相等时,将不相等的数字填到index处
 * 然后index+1,index为n就代表填了n-1个数字到前面去,及不重复的数字个数就是index
 * 这样nums也进行了修改,一举两得
 */
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int len = nums.size();
			if(len < 2) return len;
			int index = 1;
			for(int i = 1; i < len; i++)
			{
				if(nums[i] != nums[i - 1])
					nums[index++] = nums[i];
			}
			return index;
		}
};
