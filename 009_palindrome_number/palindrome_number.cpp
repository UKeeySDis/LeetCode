class Solution {
	public:
		bool isPalindrome(int x) {
			int temp = x;
			int res = 0;
			if(x < 0)   return false;
			while(x)
			{
				res = res * 10 + x %10;
				x /= 10;
			}
			return temp == res;
		}
};
