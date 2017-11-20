class Solution
{
	public:
		int maxProfit(vector<int>& prices)
		{
			int result = 0;
			int cur_min = prices[0];
			for(int i = 1; i < prices.size(); i++)
			{
				result = max(result, prices[i] - cur_min);
				cur_min = min(cur_min, prices[i]);
			}
			return result;
		}
};
