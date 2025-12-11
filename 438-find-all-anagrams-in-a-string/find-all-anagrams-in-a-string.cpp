class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if ( s.size() < p.size()) return {};
        vector<int> m(26,0),mp(26,0);
        for(auto c : p) mp[c - 'a']++;
        int n = s.size();
        int l = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            m[s[i] - 'a']++;
            if ( i - l + 1 == p.size()){
                if ( m == mp){
                    ans.push_back(l);
                }
                m[s[l] - 'a']--;
                l++;
            }
        }   
        return ans;
    }
};