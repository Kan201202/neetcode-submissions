class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        
        // 1. Move fast forward by n + 1 steps
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // 2. Move both forward until fast hits the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // 3. Delete the target node by skipping it
        slow->next = slow->next->next;
        
        return dummy.next;
    }
};