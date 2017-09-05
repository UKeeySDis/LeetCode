/* 我的想法是先找出最短的字符串
 * 然后跟其他字符依次比较
 * 如果有不同的,则将min_index减1,并更新最短字符串
 * 接着继续比较
 * 直到所有字符都比较通过
 * 则找到公共前缀
 * 否则没有
 */
class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			string s;
			int vec_len = strs.size();
			int min_prefix = -1;
			for(int i = 0; i < vec_len; i++)
			{
				if(min_prefix > strs[i].size()) min_prefix = i;
			}
			if(min_prefix == -1)  return s;
			int min_index = strs[min_prefix].size();
			while(min_index)
			{
				int i ;
				for(i = 0; i < vec_len; i++)
				{
					if(i == min_prefix)	continue;
					string temp = strs[i].substr(0, min_index);
					if(strs[min_prefix] != temp)
					{
						min_index--;
						strs[min_prefix] = strs[min_prefix].substr(0, min_index);
						break;
					}
				}
				if(i == vec_len)
					return strs[min_prefix].substr(0, min_index);
			}
			return s;
		}
};



