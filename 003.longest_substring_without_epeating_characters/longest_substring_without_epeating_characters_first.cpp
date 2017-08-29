/* 起初是打算用dp+hash来做,复杂度为O(n),但是一不小心看了下题解...
 * 发现他的方法太简便了
 * 大致的思路就是:记录当前最长的不重复子串的起始位置,以及该字符上次出现的位置
 * 比较两者,如果当前子串起始位置小与该字符上次出现的位置,则证明该子串中有重复,于是调整子串起始位置
 * 并更新该字符上次出现的位置
 */
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int last_pos = 0, res = 0;
			int len = s.length();
			map<char, int> letter;
			for(int i = 0; i < 26; i++)
			{
				letter['a' + i] = -1;
			}
			for(int i = 0; i < len; i++)
			{
				if(last_pos <= letter[s[i]])
				{
					last_pos = letter[s[i]] + 1;
				}
				letter[s[i]] = i;
				res = max(res, i - last_pos +1);
			}
			return res;   
		}
};
