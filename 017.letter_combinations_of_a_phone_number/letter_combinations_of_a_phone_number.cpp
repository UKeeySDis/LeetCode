/* O(n^3)的复杂度
 * 看了一下题解0ms的提交
 * 不用做像erase这些操作
*/
class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			if(digits.size() == 0)  return vector<string>();
			vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			vector<string> res ;
			res.push_back("");
			int len = digits.size();
			for(int i = 0; i < len; i++)
			{
				int num = digits[i] - '0';
				if(num < 0 || num > 9)  break;
				int res_len = res.size();
				for(int j = 0; j < res_len; j++)
				{
					string cur = res[0];
					res.erase(res.begin());
					int str_num_len = str[num].size();
					if(str_num_len == 0) continue;
					for(int k = 0; k < str_num_len; k++)
					{
						res.push_back(cur + str[num][k]);
					}
				}
			}
			return res;

		}
};
