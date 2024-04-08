class Solution {
public:
    long long t[100005];
    long long solve(int idx,int n,vector<vector<int>>& rides,vector<int> &first){
        if ( idx >= n ) return 0;
        if ( t[idx] != -1 ) return t[idx];
        long long notPick = solve(idx+1,n,rides,first);
        int next = lower_bound(first.begin(),first.end(),rides[idx][1]) - first.begin();
        
        long long take = rides[idx][2] + rides[idx][1] - rides[idx][0] + solve(next,n,rides,first);
        return t[idx] = max(notPick , take);

    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(t,-1,sizeof(t));
        sort(rides.begin(), rides.end());
        vector<int> first;
        for(int i = 0 ; i < rides.size() ; i++){
            first.push_back(rides[i][0]);
        }
        return solve(0,rides.size(),rides,first);
    }

};