/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 考虑到m为1的情况,需要一个辅助节点dummy作为辅助头节点
 * 用了3个辅助指针
 * head2指向第m-1个节点
 * prev指向需要移动的节点的前一个节点
 * cur指向需要移动的节点
 */
class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode dummy(-1);
			dummy.next = head;
			ListNode* head2 = NULL;
			ListNode* prev = &dummy;
			for(int i = 0; i < m - 1; i++)
			{
				prev = prev->next;
			}
			head2 = prev;
			prev = head2->next;
			ListNode* cur = prev->next;
			for(int i = m; i < n; i++)
			{
				//令cur的前一个节点的next指针指向cur的next指针指向的节点
				//这样将cur指向的节点腾了出来
				prev->next = cur->next;
				//然后将cur的next指针指向head2的next指针指向的节点
				cur->next = head2->next;
				//令head2的next指针指向cur,上一步加这一步为头插法
				head2->next = cur;
				//cur指向下一个需要移动的节点
				cur = prev->next;
			}
			//返回head
			return dummy.next;
		}
};
