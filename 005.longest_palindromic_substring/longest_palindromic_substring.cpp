class Solution
{
	public:
		string longestPalindrome(string s)
		{
			int len = s.size();
			int flag[len][len];
			int max_len  = 1, start = 0;
			memset(flag, 0, sizeof(flag));
			for(int i = 0; i < len; i++)
			{
				flag[i][i] = 1;
				for(int j = 0; j < i; j++)
				{
					flag[j][i] = (s[j] == s[i] && (i - j < 2 || flag[j + 1][i - 1]));
					if(flag[j][i] && max_len < (i - j + 1))
					{
						max_len = i - j + 1;
						start = j;
					}
				}
			}
			return s.substr(start, max_len);
		}
};


