class Solution
{
	public:
		int lengthOfLastWord(string s)
		{
			int res = 0;
			const char *str = s.c_str();
			while(*str)
			{
				if(str++ != ' ')
				{
					res++;
				}
				else if(str && str != ' ')
				{
					res = 0;
				}
			}
			return res;
		}

};

class Solution
{
	public:
		int lengthOfLastWord(string s)
		{
			if(s.empty())	return 0;
			int back = s.length() - 1;
			int res = 0;
			while(back >= 0 && s[back] == ' ')	back--;
			while(back >= 0 && s[back] != ' ')
			{
				back--;
				res++;
			}
			return res;
		}
};
