/* 用map记录罗马数字与数字之前的关系
 * 接着只用处理特殊一点的情况,即IV、IX这类
 * 前看一位字符,如果当前字符代表的值小于下一个字符代表的值,则代表是特殊情况,特殊处理
 */
class Solution {
	public:
		int romanToInt(string s)
		{
			int num = 0;
			map<char, int> m;
			m['M'] = 1000;
			m['D'] = 500;
			m['C'] = 100;
			m['L'] = 50;
			m['X'] = 10;
			m['V'] = 5;
			m['I'] = 1;
			int len = s.length();
			for(int i = 0; i < len; i++)
			{
				if(i + 1 < len)
				{
					if(m[s[i]] < m[s[i + 1]])
					{
						num += m[s[i + 1]] - m[s[i]];
						i++;
					}
					else
					{
						num += m[s[i]];
					}
				}
				else
					num += m[s[i]];
			}
			return num;
		}
};
	

				
