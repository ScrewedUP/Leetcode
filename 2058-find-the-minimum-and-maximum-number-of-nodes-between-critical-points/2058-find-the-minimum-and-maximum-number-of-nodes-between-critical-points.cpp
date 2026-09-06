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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* behind = head;
        ListNode* forward = head;
        forward = forward->next->next;
        head = head->next;
        int i = 1;
        vector<int> v;

        while(forward != NULL){
            if ( head->val > behind->val && head->val > forward->val || head->val < behind->val && head->val < forward->val){
                v.push_back(i);
            }
            i++;
            behind = behind->next;
            head = head->next;
            forward = forward->next;
        } 

        if ( v.size() < 2) return {-1,-1};

        int mini = INT_MAX;

        int maxi = v.back() - v[0];

        for(int i = 0 ; i < v.size() - 1 ; i++){
            mini = min(mini,v[i+1] - v[i]);
        }


        return {mini,maxi};
        
    }
};