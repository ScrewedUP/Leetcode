class Solution {
public:
    long long t[100005];
    map<long long,long long> m;
    vector<long long> v;

    long long solve(int i){
        if ( i >= v.size()) return 0;

        if ( t[i] != -1 ) return t[i];
        int nxt = upper_bound(v.begin(),v.end(),v[i]+2) - v.begin();

        long long take = v[i]*m[v[i]] + solve(nxt);
        long long skip = solve(i+1);

        return t[i] = max(take,skip);

    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto it : power){
            m[it]++;
        }
        set<long long> s(power.begin(),power.end());
        v.assign(s.begin(),s.end());
        memset(t,-1,sizeof(t));
        return solve(0);
    }
};