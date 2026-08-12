class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int> m;
        int l = 0;
        int ans = 0;
        int maxi = 0;
        for(int i = 0 ; i < s.size() ; i++){
            m[s[i]]++;
            maxi = max(maxi,m[s[i]]);
            while((i-l+1 - maxi) > k ){
                m[s[l]]--;
                if ( m[s[l]] == 0) m.erase(s[l]);
                l++;
            }

            ans = max(ans,i-l+1);
        }
        return ans;
    }
};