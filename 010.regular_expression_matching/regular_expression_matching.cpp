/* 才做这道题的时候,感觉有点思路但是无从下手(确实好久没刷题了)
 * 整理并借鉴了一下网上的思路,还不是最优解:
 * 1. 当源字符和匹配串都为空时,返回true,否则返回false
 * 2. 当匹配串为1个字符时,如果源字符也是一个字符并且源字符等与匹配串或者匹配串为.号时返回true,否则返回false
 * 3. 当匹配串不为'*'时,如果源字符为空,则返回false,否则两者相等或者匹配串的当前字符为.,然后进入下层递归
 * 4. 当匹配串的第二个字符为'*'，如果源字符不为空并且两者匹配，则调用递归函数匹配源字符和去掉两个字符的匹配串，若匹配返回true，否则源字符去掉首位
 * 5. 返回调用递归函数匹配源字符和去掉前两个字符的匹配串的结果
 */
class Solution {
	public:
		bool isMatch(string s, string p) {
			if (p.empty()) 
				return s.empty();
			if (p.size() == 1) {
				if(s.size() == 1 && (s[0] == p[0] || p[0] == '.'))
				{
					return true;
				}
				else 
					return false;
			}
			if (p[1] != '*') {
				if (s.empty()) 
					return false;
				return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
			}
			while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
				if (isMatch(s, p.substr(2))) 
					return true;
				s = s.substr(1);
			}
			return isMatch(s, p.substr(2));
		}
};
