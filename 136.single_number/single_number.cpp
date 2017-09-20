/* 用位运算中的异或即可完成 
 * 异或计算公式:
 * 1. a^a = 0;
 * 2. a^0 = a;
 * 3. a^(-1) = ~a;
 * 4. a^b = b^a;
 * 5. (a^b)^c = a^(b^c)
 * 因此可以利用公式1的特性来对数组进行去重(偶数次都可以)
 */
class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int res = 0;
			for(int i : nums)
			{
				res ^= i;
			}
			return res;
		}
};
