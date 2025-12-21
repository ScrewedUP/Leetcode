class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char,long long> m;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            m[s[i]]+=cost[i];
        }
        long long mini = LLONG_MAX;
        for(int i = 0 ; i < 26 ; i++){
            if ( m.find(i+'a') != m.end()){
                long long c = 0;
                char ch = i + 'a';
                for(auto it : m){
                    if ( it.first != ch ){
                        c += it.second;
                    }
                }
                mini = min(mini,c);
            }
        }
        return mini;
    }
};