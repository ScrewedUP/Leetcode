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
        vector<int> values;
        while(head!=NULL){
            values.push_back(head->val);
            head = head->next;
        }
        vector<int> dist;
        int n = values.size();
        for(int i = 1 ; i < n - 1 ; i++){
            if ( (values[i] < values[i-1] && values[i] < values[i+1]) || (values[i] > values[i-1] && values[i] > values[i+1])){
                dist.push_back(i);
            }
        }
        if ( dist.size() < 2 ) return {-1,-1};
        int mini = INT_MAX;
        for(int i = 0 ; i < dist.size()-1 ; i++){
            mini = min(mini,dist[i+1]-dist[i]);
        }
        return {mini, dist[dist.size()-1] - dist[0]};
    }
};