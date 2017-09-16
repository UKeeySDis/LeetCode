/* 找出最大的值
 * 然后以该值将数组划成左右两部分
 * 从左到该值遍历
 * 用temp变量记录当前最高的左值
 * temp与小于temp的差值就代表可以注水多少
 * 从右到该值遍历是同理的
 */
class Solution {
	public:
		int trap(vector<int>& height) {
			int len = height.size();
			int max_height = 0;
			for(int i = 0; i < len; i++)
			{
				if(height[i] > height[max_height])
					max_height = i;
			}
			int temp = 0;
			int ans = 0;
			for(int i = 0; i < max_height; i++)
			{
				if(height[i] > temp)
					temp = height[i];
				else
					ans += temp - height[i];
			}
			temp = 0;
			for(int i = len - 1; i > max_height; i--)
			{
				if(height[i] > temp)
					temp = height[i];
				else
					ans += temp - height[i];
			}
			return ans;
		}
};
