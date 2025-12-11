class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if ( s.size() < p.size()) return {};
        unordered_map<char,int> m,mp;
        for(auto c : p) mp[c]++;
        int n = s.size();
        int l = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            m[s[i]]++;
            if ( i - l + 1 == p.size()){
                if ( m == mp){
                    ans.push_back(l);
                }
                m[s[l]]--;
                if ( m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
        }   
        return ans;
    }
};