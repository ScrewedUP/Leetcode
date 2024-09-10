/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if ( head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            ListNode* next = curr->next;
            int div = __gcd(curr->val , next->val);
            ListNode * newNode = new ListNode(div);
            curr->next = newNode;
            newNode->next = next;
            curr= next;
        }
        return head;
    }
};