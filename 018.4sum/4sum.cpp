/* k-sum问题
 * 采用左右夹逼
 * 复杂度为O(n^(k-1))
 * 本题也可采用缓存的方式将复杂度降低到O(n^2)
 * 即将nums的数字两两相加,转换成2-sum问题
 */
class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int> > result;
			int len = nums.size();
			if(len < 4) return result;
			sort(nums.begin(), nums.end());

			vector<int>::iterator last = nums.end();
			for(vector<int>::iterator a = nums.begin(); a < last - 3; a++)
			{
				for(vector<int>::iterator b = a + 1; b < last - 2; b++)
				{
					vector<int>::iterator c = b + 1;
					vector<int>::iterator d = last - 1;
					while(c < d)
					{
						if(*a + *b + *c + *d < target)
						{
							++c;
						}
						else if(*a + *b + *c + *d >  target)
						{
							--d;
						}
						else
						{
							result.push_back({*a, *b, *c, *d});
							++c;
							--d;
						}
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			return result;
		}
};
