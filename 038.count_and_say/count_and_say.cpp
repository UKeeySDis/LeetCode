class Solution
{
	public:
		string countAndSay(int n)
		{
			string ans = "1";
			for(int i = 1; i < n; i++)
			{
				string temp = "";
				for(int j = 0; j < ans.size(); j++)
				{
					int count = 1;
					while(j + 1 < ans.size() && ans[j + 1] == ans[j])
					{
						count++;
						j++;
					}
					temp += to_string(count) + ans[j];
				}
				ans = temp;
			}
			return ans;
		}
};

