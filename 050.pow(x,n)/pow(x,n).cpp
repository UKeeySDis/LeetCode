class Solution
{
	public:
		double myPow(double x, int n)
		{
			if(n < 0)	return 1.0 / my_power(x, -n);
			else
				return my_power(x, n);
		}
	private:
		double my_power(double x, int n)
		{
			if(n == 0)	return 1;
			double value = my_power(x, n / 2);
			if(n % 2 == 0)
			{
				return value * value;
			}
			else
				return value * value * x;
		}
};
