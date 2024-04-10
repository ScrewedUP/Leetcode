class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>());
        deque<int> q;
        q.push_back(deck[0]);
        for(int i = 1 ; i < deck.size() ; i++){
            for(int j = 0 ; j < i-1 ; j++){
                auto curr = q[0];
                q.pop_front();
                q.push_back(curr);
            }
            q.push_front(deck[i]);
        }
        vector<int> ans;
        for(auto it : q){
            ans.push_back(it);
        }
        return ans;
    }
};