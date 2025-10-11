class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        map<long long,long long> m;
        for(auto it : power){
            m[it]++;
        }
        set<long long> s(power.begin(),power.end());
        vector<long long> v(s.begin(),s.end());
        vector<long long> t(v.size(),0);
        for(int i = 0 ; i < v.size() ; i++){
            t[i] = 0;
            for(int j = 1 ; j < 4 ; j++){
                if ( i - j >= 0 && v[i] - v[i-j] > 2){
                    t[i] = max(t[i],t[i-j]);
                }
            }
            t[i] += m[v[i]]*v[i];
            if ( i - 1 >= 0){
                t[i] = max(t[i],t[i-1]);
            }
        }
        long long ans = *max_element(t.begin(),t.end());
        return ans;
    }
};