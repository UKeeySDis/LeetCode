class Solution
{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n)
		{
			ListNode dummy(-1);
			dummy.next = head;
			ListNode* p = dummy;
			ListNode* q = dummy;
			
			for(int i = 0; i < n; i++)
			{
				p = p->next;
			}
			while(p)
			{
				if(p->next == NULL)
				{
					delete q->next;
					q->next = q->next->next;
					return dummy.next;
				}
				p = p->next;
				q = q->next;
			}
		}
};
