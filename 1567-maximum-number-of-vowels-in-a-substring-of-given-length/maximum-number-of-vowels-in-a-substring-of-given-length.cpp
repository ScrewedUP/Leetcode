class Solution {
public:
    bool f(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;
        int cnt = 0;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if ( f(s[i])){
                cnt++;
            }
            if ( i - l + 1 == k){
                ans = max(ans,cnt);
                if ( f(s[l])){
                    cnt--;
                }
                l++;
            }
        }   
        return ans;
    }
};