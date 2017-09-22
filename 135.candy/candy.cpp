/* 首先从左往右扫,若递增则将inc一直加1并且用temp数组存下来
 * 若递增曲线断了,则将inc重新置为1,重新累加并记录
 * 这样扫完一遍后只能满足从左至右递增曲线情况
 * 所以需要从右往左重新扫一遍,同样也处理递增的情况并重新维护之前的temp数组
 * 选取temp[i]和inc作为temp[i]的值
 * 最后计算temp数组的和返回
 */
class Solution {
	public:
		int candy(vector<int> &ratings) {
			const int n = ratings.size();
			int ans = n;
			vector<int> temp(n);
			for(int i = 1, inc = 1; i < n; i++)
			{
				if(ratings[i] > ratings[i - 1])
				{
					temp[i] = inc;
					++inc;
				}
				else
					inc = 1;
			}
			for(int i = n - 2, inc = 1; i >= 0; i++)
			{
				if(ratings[i] > ratings[i + 1])
				{
					temp[i] = temp[i] > inc ? temp[i] : inc;
					++inc;
				}
				else
					inc = 1;
			}
			for(int i = 0; i < n; i++)
			{
				ans += temp[i];
			}
			return ans;
		}
};


