class Solution {
public:

    /*
                3,4

        2,3     3,3    4,3

                3,2
    */

    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int,vector<int>> mx,my;
        map<pair<int,int>,int> m;
        for(auto it : b){
            mx[it[0]].push_back(it[1]);
            my[it[1]].push_back(it[0]);
            m[{it[0],it[1]}]++;
        }
        for(auto &it : mx){
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it : my){
            sort(it.second.begin(),it.second.end());
        }
        int cnt = 0;
        for(auto it : m){
            int x = it.first.first;
            int y = it.first.second;
            bool xokay = false;
            bool yokay = false;
            
            // i need to find the index of this x in mx

            int xidx = lower_bound(mx[x].begin(),mx[x].end(),y) - mx[x].begin();

            if ( mx[x].size() > 2 && xidx != 0 && xidx != mx[x].size() - 1){
                xokay = true;
            }    

            // similary for y
            int yidx = lower_bound(my[y].begin(),my[y].end(),x) - my[y].begin();

            if ( my[y].size() > 2 && yidx != 0 && yidx != my[y].size() - 1){
                yokay = true;
            }    

            if ( xokay && yokay){
                cnt++;
            }
        }
        return cnt;
    }
};