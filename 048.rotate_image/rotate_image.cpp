/* 一圈一圈的交换就行了
 * 不过这种方法比较慢了
 * 有种更优的做法是先对角线互换
 * 然后再水平互换
 */
class Solution {
	public:
		void rotate(vector<vector<int>>& matrix) {
			int len = matrix.size();
			int left = 0;
			int right = len -1;
			while(left < right)
			{
				for(int i = 0; i < right - left; i++)
				{
					swap(matrix[left][left + i], matrix[left + i][right]);
					swap(matrix[left][left + i], matrix[right][right - i]);
					swap(matrix[left][left + i], matrix[right - i][left]);
				}
				left++;
				right--;
			}
		}
};
