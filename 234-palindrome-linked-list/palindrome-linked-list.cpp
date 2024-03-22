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
    ListNode * ReverseList(ListNode * head){
        ListNode * newNode = NULL;

        while(head != NULL){
            ListNode * next = head->next;
            head->next = newNode;
            newNode = head;
            head = next;
        }
        return newNode;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = ReverseList(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if( head->val != slow->val ) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;

    }
};