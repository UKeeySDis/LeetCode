/* 1. 找出链表的中间位置
 * 2. 将链表从中间位置一分为二,并将剩下的一半翻转
 * 3. 合并这两个链表
 */
class Solution
{
	public:
		ListNode* reverse(ListNode *head)
		{
			if(head == NULL || head->next == NULL)	return head;
			ListNode *p = head->next;
			ListNode *q = head;
            q->next = NULL;
			while(p != NULL)
			{
				ListNode *temp = p->next;
				p->next = q;
				q = p;
				p = temp;
			}
			return q;
		}
		void reorderList(ListNode *head)
		{
			if(head == NULL || head->next == NULL) return;
			ListNode *slow = head;
			ListNode *fast = head;
            ListNode *prev = NULL;
			while(fast && fast->next)
			{
                prev = slow;
				fast = fast->next->next;
				slow = slow->next;
			}
            prev->next = NULL;
			slow = reverse(slow);
			ListNode *p = head;
			ListNode *q = slow;
			while(p->next != NULL)
			{
				ListNode *temp = p->next;
				p->next = q;
				p = temp;
				temp = q->next;
				q->next = p;
				q = temp;
			}
			p->next = q;
		}
};

