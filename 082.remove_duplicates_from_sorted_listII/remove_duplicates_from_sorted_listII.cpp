/* 使用了三个指针prev、temp、p
 * p指向遍历时当前的节点
 * prev指向p的前一个节点
 * temp指向prev的前一个节点
 * 当有数据重复时,将temp的next指向p即可,然后更新prev指针
 * 不重复时,维持三者的关系即可
 */
class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			if(head == NULL) return NULL;
			ListNode dummy(-1);
			dummy.next = head;
			ListNode *prev = &dummy;
			ListNode *temp = prev;
			ListNode *p = head;
			int index = -10000;
			while(p != NULL)
			{
				if(p->val == index)
				{
					p = p->next;
					while(p != NULL && p->val == index)
					{
						p = p->next;
					}
					temp->next = p;
					prev = p;
					if(p != NULL)
					{
						index = p->val;
						p = p->next;
					}
				}
				else
				{
					temp = prev;
					prev = p;
					index = p->val;
					p = p->next;
				}
			}

			return dummy.next;

		}
};

