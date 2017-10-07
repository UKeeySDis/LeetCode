class Solution
{
	public:
		bool isPalindrome(string s)
		{
			string::iterator left = s.begin();
			string::iterator right = prev(s.end());
			while(left < right)
			{
				while(!(*left >= '0' && *left <= '9') && !(*left >= 'a' && *left <= 'z') && !(*left >= 'A' && *left <= 'Z'))
				{
					left++;
				}
				while(!(*right >= '0' && *right <= '9') && !(*right >= 'a' && *right <= 'z') && !(*right >= 'A' && *right <= 'Z'))
				{
					right--;
				}
				if(left > right)
					return true;
				if(tolower(*left) != tolower(*right))
					return false;
				else
				{
					left++;
					right--;
				}
			}
			return true;
		}
};
