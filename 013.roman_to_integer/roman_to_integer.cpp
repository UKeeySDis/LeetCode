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
	

				
