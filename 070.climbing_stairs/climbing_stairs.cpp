/* 递归会超时 */
class Solution {
	public:
		int climbStairs(int n) {
			int prev = 0;
			int count = 1;
			for(int i = 1; i <= n; i++)
			{
				int temp = count;
				count += prev;
				prev = temp;
			}
			return count;
		}
};
