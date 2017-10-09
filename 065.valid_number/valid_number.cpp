/* 以合法数字为目标进行判断
 * 1. 过滤空格
 * 2. 排除第一个+/-号
 * 3. 扫描数字/小数点,要是小数点多于1个或者数字少于1个都算不合法,小数点前没有数字也是合法的...
 * 4. 接着可能有字母e,需要继续判断
 * 5. 允许有一个+/-号,但是没有小数点
 * 6. e后面也需要至少1个数字,否则不合法
 * 7. 最后把剩余的空格过滤掉,如果字符串全部都扫描完了,证明合法,否则不合法
 */
class Solution
{
	public:
		bool isNumber(string s)
		{
			int i = 0;
			while(s[i] == ' ')	i++;
			if(s[i] == '+' || s[i] == '-') i++;
			int flag_point = 0, flag_num = 0;
			for(; (s[i] >= '0' && s[i] <= '9') || s[i] == '.'; i++)
			{
				if(s[i] == '.')	flag_point++;
				if(s[i] >= '0' && s[i] <= '9')	flag_num++;
			}
			if(flag_point > 1 || flag_num == 0)	return false;
			if(s[i] == 'e')
			{
				i++;
				if(s[i] == '+' || s[i] == '-')	i++;
				for(flag_num = 0; s[i] >= '0' && s[i] <= '9'; i++)
				{
					flag_num++;
				}
				if(flag_num == 0)	return false;
			}
			while(s[i] == ' ')	i++;
			if(i == s.size())	return true;
			else
				return false;
		}
};
