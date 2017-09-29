class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = dummy.next;
        ListNode *next = cur->next;
        for(; next; prev = cur, cur = cur->next, next = cur ? cur->next : NULL)
        {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};
