/* 处理进位溢出vector的情况 */
class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int carry = 0;
			int len = digits.size();
			digits[len - 1] += 1;
			if(digits[len - 1] == 10)
			{
				carry = 1;
				digits[len - 1] = 0;
			}
			for(int i = len - 2; i >= 0; i--)
			{
				digits[i] += carry;
				if(digits[i] >= 10)
				{
					carry = digits[i] / 10;
					digits[i] %= 10;
				}
				else carry = 0;
			}
			if(carry == 1)
			{
				digits[0] %= 10;
				digits.insert(digits.begin(), 1);
			}
			return digits;
		}
};
