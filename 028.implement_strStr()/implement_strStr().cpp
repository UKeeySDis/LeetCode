class Solution
{
	public:
		int strStr(string haystack, string needle)
		{
			if(needle.empty())	return 0;
			const int len = haystack.size() - needle.size() + 1;
			for(int i = 0; i < len; i++)
			{
				int j = i;
				int count = 0;
				while(j < haystack.size() && count < needle.size() && haystack[j] == needle[count])
				{
					j++;
					count++;
				}
				if(count == needle.size())
					return i;
			}
			return -1;
		}
};
