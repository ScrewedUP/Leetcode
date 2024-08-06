class Solution {
public:
    int minimumPushes(string word) {
        
            set<char> s;
        for(auto it:word) s.insert(it);
        int ans=0;
        vector<int> mp(26,0);
        for(auto it:word)mp[it-'a']++;
        int cnt=1;
        int a=0;
        sort(mp.begin(),mp.end(),greater<int>());
        for(int it=0;it<26;it++){
            if(mp[it]==0)continue;
            a++;
            ans+=mp[it]*cnt;
            if(a>=8){
                cnt++;
                a=0;
            }
        }
        return ans;
        
    }
};