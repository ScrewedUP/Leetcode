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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode * he = newHead;
        ListNode* start = head;
        while ( start->next != NULL){
            if ( start->val == 0){
                int sum = 0;
                ListNode * temp = start;
                temp = temp->next;
                while ( temp != NULL && temp->val != 0){
                    sum += temp->val;
                    temp = temp->next;
                }
                start = temp;
                ListNode * currNode = new ListNode(sum);
                he->next = currNode;
                he = he->next;
            }
        }
        return newHead->next;
    }
};