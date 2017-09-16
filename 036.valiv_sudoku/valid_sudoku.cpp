/* 依次检查行/列/3宫格即可 */
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			for(int i = 0; i < 9; i++)
			{
				bool used[9];
				fill(used, used + 9, false);
				for(int j = 0; j < 9; j++)
				{
					if(!check(board[i][j], used))
						return false;
				}
				fill(used, used + 9, false);
				for(int j = 0; j < 9; j++)
				{
					if(!check(board[j][i], used))
						return false;
				}
			}
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					bool used[9];
					fill(used, used + 9, false);
					for(int k = i * 3; k < i * 3 + 3; k++)
					{
						for(int l = j * 3; l < j * 3 + 3; l++)
						{
							if(!check(board[k][l], used))
								return false;
						}
					}
				}
			}
			return true;
		}
		bool check(char c, bool used[9])
		{
			if(c == '.')
				return true;
			if(used[c - '1'])
				return false;
			used[c - '1'] = true;
			return true;
		}
};
