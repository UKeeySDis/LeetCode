class Solution
{
	public:
		ListNode *detectCycle(ListNode *head)
		{
			ListNode *fast_pointer = head;
			ListNode *slow_pointer = head;
			while(fast_pointer && fast_pointer->next)
			{
				fast_pointer = fast_pointer->next->next;
				slow_pointer = slow_pointer->next;
				if(fast_pointer == slow_pointer)
				{
					fast_pointer = head;
					while(1)
					{
						if(fast_pointer == slow_pointer)
						{
							return fast_pointer;
						}
						fast_pointer = fast_pointer->next;
						slow_pointer = slow_pointer->next;
					}
				}
			}
			return NULL;
		}
};
