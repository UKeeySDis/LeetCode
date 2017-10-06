class Solution
{
	public:
		bool hasCycle(ListNode *head)
		{
			ListNode *fast_pointer = head;
			ListNode *slow_pointer = head;
			while(fast_pointer && fast_pointer->next)
			{
				slow_pointer = slow_pointer->next;
				fast_pointer = fast_pointer->next->next;
				if(slow_pointer == fast_pointer)	return true;
			}
			return false;
		}
};
