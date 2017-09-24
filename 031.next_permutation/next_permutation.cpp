class Solution
{
	public:
		void nextPermutation(vector<int> &nums)
		{
			int len = nums.size();
			if(len <= 1)	return;
			vector<int>::iterator first = nums.begin();
			vector<int>::iterator last = nums.end();
			vector<int>::iterator i = last;
			--i;
			while(1)
			{
				vector<int>::iterator ii = i;
				--i;
				if(*i < *ii)
				{
					vector<int>::iterator j = last;
					while(!(*--j > *i));
					swap(*i, *j);
					reverse(ii, last);
					return;
				}
				if(i == first)
				{
					reverse(i, last);
					return;
				}
			}
		}
};
