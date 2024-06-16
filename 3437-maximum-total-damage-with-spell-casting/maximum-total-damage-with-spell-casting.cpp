class Solution {
public:
    long long t[100001];
    long long solve(int idx,vector<int> &ans,map<int,int> &m){
        if ( idx >= ans.size() ) return 0;
        if ( t[idx] != -1 ) return t[idx];

        long long take = ((long long)m[ans[idx]] * (long long)ans[idx]);
        if ( idx + 1 < ans.size() && ans[idx] + 2 >= ans[idx+1] ){
            long long curr = ans[idx];
            int i = idx + 1;
            while ( i < ans.size() && ans[i] <= curr + 2){
                i++;
            }
            take += solve(i,ans,m);
        }
        else if ( idx + 1 < ans.size() && ans[idx] + 2 < ans[idx+1]){
            take += solve(idx+1,ans,m);
        }
        long long notTake = solve(idx+1,ans,m);
        return t[idx] = max(take,notTake);
    }
    long long maximumTotalDamage(vector<int>& v) {
        memset(t,-1,sizeof(t));
        sort(v.begin(),v.end());
        map<int,int> m;
        for(auto it : v) m[it]++;
        vector<int> ans;
        for(auto it : m ) ans.push_back(it.first);
        return solve(0,ans,m);
        
    }
};