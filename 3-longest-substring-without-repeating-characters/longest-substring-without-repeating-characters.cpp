class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxi = 0;
        int n = s.size();
        unordered_map<char,int> m;
        for(int r = 0 ; r < n ; r++){
            m[s[r]]++;
            while(m[s[r]] > 1){
                m[s[l]]--;
                if ( m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};