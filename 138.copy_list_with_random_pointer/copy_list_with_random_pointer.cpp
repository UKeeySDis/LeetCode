class Solution
{
	public:
		RandomListNode *copyRandomList(RandomListNode *head)
		{
			if(head == NULL)	return NULL;
			for(RandomListNode *cur = head; cur;)
			{
				RandomListNode *copy_node = new RandomListNode(cur->label);
				copy_node->next = cur->next;
				cur->next = copy_node;
				cur = copy_node->next;
			}
			for(RandomListNode *cur = head; cur;)
			{
				if(cur->random != NULL)
				{
					cur->next->random = cur->random->next;
				}
				cur = cur->next->next;
			}
			RandomListNode *new_head = head->next;
			for(RandomListNode *cur = head, *copy_cur = new_head; cur;)
			{
				cur->next = cur->next->next;
				cur = cur->next;
				if(cur == NULL)	break;
				copy_cur->next = copy_cur->next->next;
				copy_cur = copy_cur->next;
			}
			return new_head;
		}
};
