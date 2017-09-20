/* 利用位运算完成
 * 提出数组中的每个数的第i位,然后用sum记录下来该位的总数
 * 如果sum%3为0证明单独存在的那个数的该位为0
 * 如果不为0,证明单独存在的那个数该位为1
 * 通过(sum%3)<<i可以将单独存在的数一位一位提取出来
 */
class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int res = 0;
			for (int i = 0; i < 32; ++i) {
				int sum = 0;
				for (int j = 0; j < nums.size(); ++j) {
					sum += (nums[j] >> i) & 1;
				}
				res |= (sum % 3) << i;
			}
			return res;
		}
};
