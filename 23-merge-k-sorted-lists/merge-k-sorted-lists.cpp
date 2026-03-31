class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto it : lists){
            if(it) pq.push(it);
        }

        ListNode* temp = new ListNode(0);
        ListNode* head = temp;

        while(!pq.empty()){
            auto tp = pq.top();
            // cout << tp->val << endl;
            pq.pop();

            temp->next = tp;
            temp = temp->next;

            if(tp->next){
                pq.push(tp->next);
            }
        }

        return head->next;
    }
};