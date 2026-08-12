class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> m;
        int l = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            m[s[i]]++;

            while ( m[s[i]] > 1){
                m[s[l]]--;
                l++;
            }

            ans = max(ans,i-l+1);
        }
        return ans;
    }
};