/* 先取得链表的长度len以及最后一个不为空的结点p
 * 将p->next指向head,使链表形成一个环
 * 这样只需要遍历到链表的第len - k个节点,然后将第len - k个节点的next节点置为head
 * 接着让消除环返回即可
 * 注意k是从右往左数....开始把题意搞错了
 * 而且注意k大于总长度时,需要做模运算
 */
class Solution
{
	public:
		ListNode* rotateRight(ListNode* head, int k)
		{
			if(head == NULL || k == 0)	return head;
			int len = 1;
			ListNode *p = head;
			while(p->next)
			{
				len++;
				p = p->next;
			}
			k = len - k % len;
			p->next = head;
			for(int step = 0; step < k; step++)
			{
				p = p->next;
			}
			head = p->next;
			p->next = NULL;
			return head;
		}
};
