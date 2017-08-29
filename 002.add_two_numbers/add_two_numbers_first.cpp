/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
/* 本来尝试用一个新的链表来保存结果,但是最后居然内存超过限制了。所以就用原来的链表来存。唯一需要考虑的是,两个链表长度相等,但最后一个结点进位的情况*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *p1 = l1;
        ListNode *p2 = l2;
        int flag = 0;
        int carry = 0;
        while(p1 || p2)
        {
            int num;
            if(p1 && p2)
            {
                num = p1->val + p2->val + carry;
            }
            else if(p1)
            {
                num = p1->val + carry;
                flag = 1;
            }
            else if(p2)
            {
                num = p2->val + carry;
                flag = 2;
            }
            if((carry = num / 10))
            {
                num %= 10;
            }
            if(!flag)
            {
                p1->val = p2->val = num;
                if(!(p1->next) && !(p2->next) && carry)
                {
                    ListNode *last = new ListNode(carry);
                    p1->next = last;
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(flag == 1)
            {
                p1->val = num;
                if(!(p1->next) && carry)
                {
                    ListNode *last = new ListNode(carry);
                    p1->next = last;
                    break;
                }
                p1 = p1->next;
            }
            else
            {
                p2->val = num;
                if(!(p2->next) && carry)
                {
                    ListNode *last = new ListNode(carry);
                    p2->next = last;
                    break;
                }
                p2 = p2->next;
            }
        }
        if(!flag || flag == 1)  return l1;
        else return l2;
    }
};
