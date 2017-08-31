/* 放字符的顺序是从上到下再从下到上这样的顺序
 * flag用来记录顺序
 * now_row用来记录当前行,如果到底了则往上,到顶则往下
 */ 
class Solution {
	public:
		string convert(string s, int numRows) {
			int now_row = 0, flag = 1;
			int len = s.length();
			vector<string >s_row(numRows);
			string res;
			if(numRows == 1)    return s;
			for(int i = 0; i < len; i++)
			{
				s_row[now_row] += s[i];
				if(numRows - 1 == now_row)
				{
					flag  = -1;
				}
				else if(0 == now_row)
				{
					flag = 1;
				}
				now_row += flag;
			}
			for(int i = 0; i < numRows; i++)
			{
				res += s_row[i];
			}
			return res;
		}
};
