class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while (start != nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end != nullptr) {
                prefixSum += end->val;
                if (prefixSum == 0) {
                    start->next = end->next;
                }
                end = end->next;
            }

            start = start->next;
        }
        return front->next;
    }
};