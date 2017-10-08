class Solution
{
	public:
		string addBinary(string a, string b)
		{
			string ans;
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			int len = a.size() > b.size() ? a.size() : b.size();
			int carry = 0;
			for(int i = 0; i < len; i++)
			{
				int num_a = i < a.size() ? a[i] - '0' : 0;
				int num_b = i < b.size() ? b[i] - '0' : 0;
				int num = (num_a + num_b + carry) % 2;
				carry = (num_a + num_b) / 2;
				ans.insert(ans.begin(), num + '0');
			}
			if(carry)
			{
				ans.insert(ans.begin(), '1');
			}
			return ans;
		}
};
