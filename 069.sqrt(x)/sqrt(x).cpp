class Solution
{
	public:
		int mySqrt(int x)
		{
			int left = 0;
			int right = x / 2 + 1;
			if(x < 2)	return x;
			while(left <= right)
			{
				int mid = (left + right) / 2;
				if(x / mid > mid)
				{
					left = mid + 1;
				}
				else if(x / mid < mid)
				{
					right = mid - 1;
				}
				else
					return mid;
			}
			return right;
		}
};

