/* 使用两个bool数组记录哪行哪列需要清0 */
class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			bool flag_row[m];
			bool flag_col[n];
			fill(flag_row, flag_row + m, true);
			fill(flag_col, flag_col + n, true);
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(matrix[i][j] == 0)
					{
						flag_row[i] = false;
						flag_col[j] = false;
					}
				}
			}
			for(int i = 0; i < m; i++)
			{
				if(flag_row[i] == false)
				{
					for(int j = 0; j < n; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}
			for(int i = 0; i < n; i++)
			{
				if(flag_col[i] == false)
				{
					for(int j = 0; j < m; j++)
					{
						matrix[j][i] = 0;
					}
				}
			}
		}
};
