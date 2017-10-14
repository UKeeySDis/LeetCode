/* 当字符为'('时压入该字符的下标
 * 为')'时,分以下几种情况(last指向可以进行匹配的字符起始的前一个位置):
 *		1. 若当前栈为空,证明没有可以匹配的左括号,则将last赋为i
 *		2. 若当前栈不为空,证明可以进行匹配,弹出栈顶元素,此时又会分情况:
 *			1. 当弹出元素后该栈为空,证明本次连续的最长匹配的长度为i-last
 *			2. 若此时栈不为空,说明后面的字符还有可能进行匹配,则本次长度为i-unmatch.top()
 */
class Solution
{
	public:
		int longestValidParentheses(string s)
		{
			int last = -1, res = 0;
			stack<int> unmatch;
			for(int i = 0; i < s.length(); i++)
			{
				if(s[i] == '(')
				{
					unmatch.push(i);
				}
				else
				{
					if(unmatch.empty())
					{
						last = i;
					}
					else
					{
						unmatch.pop();
						if(unmatch.empty())
						{
							res = max(res, i - last);
						}
						else
						{
							res = max(res, i - unmatch.top());
						}
					}
				}
			}
			return res;
		}
};
