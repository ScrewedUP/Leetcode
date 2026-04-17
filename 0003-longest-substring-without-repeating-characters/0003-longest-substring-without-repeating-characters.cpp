class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        map<int,int> m;
        int maxi = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if ( m.find(s[i]) != m.end()){
                while(m[s[i]] > 0 ){
                    m[s[l]]--;
                    if ( m[s[l]] == 0) m.erase(s[l]);
                    l++;
                }
            }
            m[s[i]]++;
            maxi = max(maxi,i-l+1);
        }
        return maxi;
    }
};