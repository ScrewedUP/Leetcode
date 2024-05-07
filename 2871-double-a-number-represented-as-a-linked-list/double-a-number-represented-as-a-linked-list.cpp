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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while( head != NULL){
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        ListNode* newHead = reverseList(temp);
        temp = newHead;
        ListNode* he = temp;
        int cnt = 0;
        int carry = 0;
        while(newHead){
            cnt++;
            int value = newHead->val;
            value *= 2;
            value+=carry;
            newHead->val = (value%10);
            carry = value/10; 
           newHead= newHead->next;
           if ( cnt > 1 ) temp = temp->next;
            
        }
        if ( carry > 0 ){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        he = reverseList(he);
        return he;
    }
};