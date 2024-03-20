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
    void solve(ListNode *head, pair<ListNode *, ListNode *> p, int x, int a, int b){
        if(!head){
            return;
        }
        x++;

        ListNode *tmp = head, *t2 = head->next;
        if(x == a)
            tmp->next = p.first;
        if(x == b+1){
            tmp->next = NULL;
            p.second->next = t2;
        }
        solve(t2, p, x, a, b);
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        pair<ListNode *, ListNode *> pa;
        ListNode *p = list2;
        if(!list2)  return list1;
        else if(!list1) return list2;
        else if(!list1 && !list2)   return list1;
        pa.first = list2;

        while(p->next) p = p->next;
        pa.second = p;

        solve(list1, pa, 0, a, b);
        return list1;
    }
};