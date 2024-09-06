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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* nxt = dummy;
        while(nxt->next){
            if ( m.find(nxt->next->val) != m.end()){
                nxt->next = nxt->next->next;
            }
            else{
                nxt = nxt->next;
            }
        }
        
        return dummy->next;
    }
};