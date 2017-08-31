/* 用long double来存,可以直截了当的判溢出*/
class Solution {
	public:
		int reverse(int x) {
			long double res = 0;
			while(x)
			{
				res = res * 10 + x %10;
				x /= 10;
			}
			if(res > INT_MAX) return 0;
			else if(res < INT_MIN) return 0;
			else return res;
		}
};
