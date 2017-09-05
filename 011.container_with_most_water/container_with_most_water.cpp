/* 如果left的长度小于right,证明短板在left
 * 由于底边目前是最大的
 * 所以只有通过移动left来找到新的可能的更大面积
 * 反之,如果right>left,则移动right
 */
class Solution
{
	public:
		int maxArea(vector<int>& height) {
			int left, right, max_area;
			left = 0;
			right = height.size() - 1;
			max_area = -1;
			while(left <= right)
			{
				max_area = max(max_area, min(height[left], height[right]) * ((right - left)))
				if(height[left] < height[right])
					left++;
				else
					right--;
			}

		}
};
