class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int x = INT_MAX;
        for(auto it : tasks){
            x = min(x,it[0]+it[1]);
        }
        return x;
    }
};