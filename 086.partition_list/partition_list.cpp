/* 找到第一个比x大或者等于的节点
 * 然后用head2记录下来,并且用flag记录head2的前一个节点
 * 把在head2后面的并且比x小的节点移动到flag与head2之间
 * 因为要求顺序不能变,所以将flag前移
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        int f = 0;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *head2 = &dummy;
        ListNode *flag = NULL;
        ListNode *cur = head2->next;
        ListNode *prev = head2;
        while(cur != NULL)
        {
            if(!f && cur->val >= x)  
            {  
				f = 1;
				head2 = cur;
				flag = prev;
            }
            else if(f && cur->val < x)  
            {
				prev->next = cur->next;
				cur->next = head2;
				flag->next = cur;
				flag = cur;
            }
			prev = cur;     
			cur = cur->next;
        }
		return dummy.next;
	}
};
