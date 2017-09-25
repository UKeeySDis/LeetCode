class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			int index = head->val;
			ListNode dummy(-1);
			dummy.next = head;
			ListNode *p = head->next;
			ListNode *prev = head;
			while(p != NULL)
			{
				while(p != NULL && index == p->val)
				{
					if(p)
						p = p->next;
				}
				prev->next = p;
				prev = p;
				if(p != NULL)
				{
					index = p->val;
					p = p->next;
				}
			}
			return head;
		}
};
