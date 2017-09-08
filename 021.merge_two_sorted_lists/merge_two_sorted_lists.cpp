/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 考查链表操作的一道题 */
class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode res(0);
			ListNode *p = &res;
			while(l1 && l2)
			{
				if(l1->val < l2->val)
				{
					p->next = l1;
					l1 = l1->next;
				}
				else
				{
					p->next = l2;
					l2 = l2->next;
				}
				p = p->next;
			}
			p->next = l1 ? l1 : l2;
			return res.next;
		}
};
