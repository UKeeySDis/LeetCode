/* 这道题有点坑,主要要考虑以下情况:
 * 1.有多个正负号直接取0
 * 2.遇到非数字符号以及非正负号,直接返回前面截取的数字
 * 3.超出int的范围,要改成2147483647或-2147483648
 * 思路挺简单的:遇到正负号,前看一个符号,如果不是数字,直接返回0;
 *				遇到空格时,如果此时res已经被改变了,证明空格处于数字之间,直接退出循环,返回之前截取的数字
 *				出循环之后,该乘负数的乘负数,该判越界的判越界
 */
class Solution {
	public:
		int myAtoi(string str) {
			double res = 0;
			int flag_s = 0, change = 0;
			int len = str.length();
			for(int i = 0; i < len; i++)
			{
				if(str[i] == '-' || str[i] == '+')
				{
					if(!(str[i + 1] >= '0' && str[i + 1] <= '9'))
						return 0;
					if(str[i] == '-')
						flag_s++;
				}
				else if(str[i] >= '0' && str[i] <= '9')
				{
					change = 1;
					res = res * 10 + str[i] - '0';
				}
				else if(str[i] == ' ' && !change)
				{
					continue;
				}
				else break;
			}
			if(flag_s == 1 && res != 0)
			{
				res = res * -1;
			}
			if(res > 2147483647)  return res = 2147483647;
			else if(res < -2147483648) return res = -2147483648;
			return res;

		}
};
