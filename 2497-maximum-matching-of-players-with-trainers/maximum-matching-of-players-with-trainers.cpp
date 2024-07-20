class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        map<int,int> m;
        for(auto it : trainers){
            m[it]++;
        }
        sort(players.begin(),players.end());
        int cnt = 0;
        for(int i = 0 ; i < players.size() ; i++){
            int curr = players[i];
            auto req = m.lower_bound(curr);
            if ( req != m.end() ){
                cnt++;
                m[(*req).first]--;
                if ( m[(*req).first] == 0 ) m.erase(req);
            }
        }
        return cnt;
    }
};