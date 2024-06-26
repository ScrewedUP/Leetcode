class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        map<char,int> m;
        int left = 0;
        int cnt = 0;
        for(int right = 0;right < s.size() ;right++){
            m[s[right]]++;
            while ( m[s[right]] > 1 ){
                m[s[left]]--;
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};