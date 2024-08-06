class Solution {
public:
    const int m = 1e9 +7;
    int numSub(string s) {
        int ans = 0;
        long long cnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if ( s[i] == '1'){
                cnt++;
            }
            else{

                ans = (ans + cnt*(cnt+1)/2)%m;
                cnt = 0;
            }
        }
        if ( cnt > 0 ){
            ans = (ans + cnt*(cnt+1)/2)%m;
        }
        return ans;
    }
};