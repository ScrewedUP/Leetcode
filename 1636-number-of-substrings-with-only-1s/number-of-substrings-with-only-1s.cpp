class Solution {
public:
    int numSub(string s) {
        int M = 1e9 + 7;
        long long ans = 0;
        long long cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == '1'){
                cnt++;
            }
            else{
                if ( cnt > 0 ){
                    ans += cnt*(cnt+1)/2;
                    ans %= M;
                }
                cnt = 0;
            }

        }
        if ( cnt > 0 ){
            ans += cnt*(cnt+1)/2;
            ans %= M;
            
        }
        return ans;
    }
};