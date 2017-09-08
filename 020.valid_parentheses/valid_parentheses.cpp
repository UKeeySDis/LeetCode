/* 很典型的使用栈的例子
 * 当符号为) ] }时,需要判断栈是否为空
 * 若为空,直接return false
 * 不为空才继续判断栈顶是否合法
 * 很奇怪的一点是....没加if(len == 0)	return false;时
 * 运行了3ms,加了之后0ms....
 * leetcode的样例也太扯了
 */
class Solution {
	public:
		bool isValid(string s) {
			stack<char> st;
			int len = s.size();
			if(len == 0)    return false;
			for(int i = 0; i < len; i++)
			{
				if(s[i] == '(' || s[i] == '{' || s[i] == '[')
					st.push(s[i]);
				else if(!st.empty())
				{
					char c = st.top();
					if(s[i] == ')' && c == '(')
					{
						st.pop();
					}
					else if(s[i] == ']' && c == '[')
					{
						st.pop();
					}
					else if(s[i] == '}' && c == '{')
					{
						st.pop();
					}
					else return false;
				}
				else return false;
			}
			return st.empty();
		}
};
