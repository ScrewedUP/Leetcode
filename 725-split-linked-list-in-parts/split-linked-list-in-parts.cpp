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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* start = head;
        int cnt = 0;
        while(start != NULL){
            start = start->next;
            cnt++;
        }
        start = head;
        int t = k;
        if ( k >= cnt){
            while(start != NULL){
                ans.push_back(new ListNode(start->val));
                start = start->next;
                t--;
            }
            for(int i = 0 ; i < t ; i++){
                ans.push_back(NULL);
            }
        }
        else{
            int g = cnt % k;
            int totalele = cnt / k;
            while(start != NULL){
                ListNode* curr = new ListNode(start->val);
                ListNode* h1 = curr;
                start = start->next;
                for(int i = 0 ; i < totalele-1 ; i++){
                    ListNode* nxt;
                    if ( start!=NULL) nxt = new ListNode(start->val);
                    h1->next = nxt;
                    h1 = nxt;
                    if ( start != NULL ) start = start->next;
                }
                if ( g > 0 ){
                    g--;
                    ListNode* nx = new ListNode(start->val);
                    h1->next = nx;
                    h1 = curr;
                    start = start->next;
                }
                
                ans.push_back(curr);
            }
        }
        return ans;
    }
};