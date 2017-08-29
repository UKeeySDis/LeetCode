/*************************************************************************
  > File Name: add_two_numbers_first.cpp
  > Author: Ukey
  > Mail: gsl110809@gmail.com
  > Created Time: 2017年08月29日 星期二 14时58分00秒
 ************************************************************************/

#include <iostream>
using namespace std;
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *res;
			ListNode *p1 = l1;
			ListNode *p2 = l2;
			int num, carry_flag, flag;
			while(p1 || p2)
			{
				if(p1 && p2)
				{
					num = p1->val + p2->val + carry_flag;
					flag = 0;
				}
				else if(p1)
				{
					num = p1->val + carry_flag;
					flag = 1;
				}
				else
				{
					num = p2->val + carry_flag;
					flag = 2;
				}
				if((carry_flag = num / 10))
				{
					num %= 10;
				}
				p1->val = num;
				p2->val = num;
				p1++;
				p2++;
			}
			if(flag == 0 || flag == 1)   return p1;
			else  return p2; 
		}
};
