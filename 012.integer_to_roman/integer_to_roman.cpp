/* 这道题需要去查一下罗马数字的表示方法 
 * 可以发现,每三个符号,中间的那个的数值代表由大的减小,比如IV,值为V-I
 * 利用这一点,可以先满足大的依次遍历赋值即可
 */
class Solution {
public:
    string intToRoman(int num) {
        string roman_num[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX","V", "IV", "I"};
        int int_num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res;
        for(int i = 0; num != 0; i++)
        {
            while(num >= int_num[i])
            {
                res += roman_num[i];
                num -= int_num[i];
            }
        }
        return res;
    }
};
